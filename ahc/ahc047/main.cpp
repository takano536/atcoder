#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <random>
#include <set>
#include <string>
#include <utility>
#include <vector>

#include <cassert>
#include <chrono>
#include <climits>
#include <functional>
#include <memory>
#include <unordered_map>

constexpr int N = 36;
constexpr int M = 12;
constexpr int L = 1e6;
constexpr int CHAR_NUM = 6;

namespace chatgpt {

using namespace std;

// 行列乗算（n×nの正方行列を1次元配列で表現）
struct PairHash {
    size_t operator()(const std::pair<int, int> &p) const {
        return (size_t(p.first) << 16) ^ size_t(p.second);
    }
};

double compute_word_probability(
    const std::vector<char> &word,
    size_t L,
    const std::vector<char> &C,
    const std::vector<std::vector<int>> &A
) {
    int word_len = static_cast<int>(word.size());
    int n = 0;

    std::unordered_map<std::pair<int, int>, int, PairHash> states;
    for (int j = 0; j < M; ++j) {
        states[{0, j}] = n++;
        for (int i = 0; i + 1 < word_len; ++i) {
            if (word[i] == C[j]) {
                states[{i + 1, j}] = n++;
            }
        }
    }

    std::unique_ptr<double[]> X(new double[n * n]());
    for (const auto &[key, j] : states) {
        int len = key.first;
        int u = key.second;

        for (int v = 0; v < M; ++v) {
            int s = 0;
            while (s < len + 1) {
                bool match = true;
                for (int i = s; i < len; ++i) {
                    if (i - s >= word_len || word[i - s] != word[i]) {
                        match = false;
                        break;
                    }
                }
                if (match && word[len - s] == C[v]) break;
                ++s;
            }

            int next_len = len + 1 - s;
            if (next_len == word_len) continue;
            auto it = states.find({next_len, v});
            if (it != states.end()) {
                int i = it->second;
                X[i * n + j] += static_cast<double>(A[u][v]) / 100.0;
            }
        }
    }

    // 行列累乗 Y = X^(L-1)
    std::unique_ptr<double[]> Y(new double[n * n]());
    for (int i = 0; i < n; ++i) {
        Y[i * n + i] = 1.0;
    }

    std::unique_ptr<double[]> base(new double[n * n]);
    std::copy(X.get(), X.get() + n * n, base.get());

    size_t power = L - 1;
    std::unique_ptr<double[]> tmp(new double[n * n]);

    while (power > 0) {
        if (power & 1) {
            std::fill(tmp.get(), tmp.get() + n * n, 0.0);
            for (int i = 0; i < n; ++i) {
                for (int k = 0; k < n; ++k) {
                    double aik = Y[i * n + k];
                    if (aik == 0.0) continue;
                    for (int j = 0; j < n; ++j) {
                        tmp[i * n + j] += aik * base[k * n + j];
                    }
                }
            }
            std::swap(Y, tmp);
        }

        std::fill(tmp.get(), tmp.get() + n * n, 0.0);
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < n; ++k) {
                double aik = base[i * n + k];
                if (aik == 0.0) continue;
                for (int j = 0; j < n; ++j) {
                    tmp[i * n + j] += aik * base[k * n + j];
                }
            }
        }
        std::swap(base, tmp);
        power >>= 1;
    }

    int init = (C[0] == word[0]) ? states[{1, 0}] : states[{0, 0}];

    double ret = 1.0;
    for (int i = 0; i < n; ++i) {
        ret -= Y[i * n + init];
    }

    if (ret < 0.0) ret = 0.0;
    if (ret > 1.0) ret = 1.0;

    return ret;
}

class Annealer {
  private:
    const vector<string> s;
    const vector<int> p;
    const string c;

    const int seed = 42;
    double time_limit = 0.64;  // 秒
    double start_temp = 100.0;
    double end_temp = 1e-4;
    int max_rate = 5;

    vector<vector<int>> matrix;
    vector<vector<int>> best_matrix;
    int best_score = INT_MIN;
    int current_score = 0;

    mt19937 rng;
    chrono::steady_clock::time_point start_time;

  public:
    Annealer(
        const vector<string> &s,
        const vector<int> p,
        const string &c,
        const vector<vector<int>> &a
    ) : s(s), p(p), c(c), matrix(a), rng(seed) {
        current_score = calc_score(matrix);
        best_matrix = matrix;
        best_score = current_score;
    }

    void run() {
        // cerr << "Score: " << current_score << '\n';
        start_time = chrono::steady_clock::now();

        std::array<int, M> from;
        std::array<int, M> to;
        std::array<int, M> rates;

        std::uniform_int_distribution<int> rate_dist(1, max_rate);
        std::uniform_int_distribution<int> to_dist(0, M - 1);
        std::uniform_real_distribution<double> prob_dist(0.0, 1.0);

        std::array<int, M> candidate_rows;

        while (elapsed_time() < time_limit) {
            for (int i = 0; i < M; ++i) {
                rates[i] = rate_dist(rng);
                int count = 0;

                // rowsに相当する候補を事前割り当て済み配列に格納
                for (int j = 0; j < M; ++j) {
                    if (matrix[i][j] > rates[i]) {
                        candidate_rows[count++] = j;
                    }
                }

                // 移動元の選択（候補がないときはランダムな位置）
                from[i] = count > 0 ? candidate_rows[uniform_int_distribution<int>(0, count - 1)(rng)] : to_dist(rng);
                to[i] = to_dist(rng);

                // 無意味な遷移を防ぐ
                if (from[i] == to[i]) {
                    // 無効化のため rate を 0 に（後の処理でスキップされる）
                    rates[i] = 0;
                    continue;
                }

                matrix[i][from[i]] -= rates[i];
                matrix[i][to[i]] += rates[i];
            }

            int new_score = calc_score(matrix);
            int delta = new_score - current_score;

            double t = temperature(elapsed_time() / time_limit);
            if (delta >= 0 || prob_dist(rng) < exp(delta / t)) {
                current_score = new_score;
                if (new_score > best_score) {
                    best_score = new_score;
                    best_matrix = matrix;
                }
            } else {
                // 差し戻し（rate[i] == 0 のものはスキップされる）
                for (int i = 0; i < M; ++i) {
                    if (rates[i] > 0) {
                        matrix[i][from[i]] += rates[i];
                        matrix[i][to[i]] -= rates[i];
                    }
                }
            }
            print_result();
        }
    }

    pair<int, vector<vector<int>>> get_result() const {
        // cerr << "Best score: " << best_score << '\n';
        for (int i = 0; i < M; i++) {
            if (accumulate(matrix[i].begin(), matrix[i].end(), 0) != 100) {
                return {INT_MIN, {}};
            }
        }
        return {best_score, best_matrix};
    }

    void print_result() const {
        // cerr << "Best score: " << best_score << '\n';
        // cerr << "Best matrix:\n";
        for (int i = 0; i < M; ++i) {
            cout << c[i] << ' ';
            for (int j = 0; j < M; ++j) {
                cout << best_matrix[i][j] << ' ';
            }
            cout << '\n';
        }
    }

  private:
    int calc_score(const vector<vector<int>> &matrix) const {
        double total = 0.0;
        for (int i = 0; i < N; i++) {
            std::vector<char> word(s[i].begin(), s[i].end());
            std::vector<char> chars(c.begin(), c.end());
            total += chatgpt::compute_word_probability(word, L, chars, matrix) * p[i];
        }
        return std::round(total);
    }

    double
    elapsed_time() const {
        return chrono::duration<double>(chrono::steady_clock::now() - start_time).count();
    }

    double temperature(double progress) const {
        return start_temp + (end_temp - start_temp) * progress;
    }
};

}  // namespace chatgpt

int main() {

    int n, m, l;
    std::cin >> n >> m >> l;

    std::vector<std::pair<std::string, int>> fav_strs(n);
    std::vector<std::string> s(n);
    std::vector<int> p(n);
    for (int i = 0; auto &[si, pi] : fav_strs) std::cin >> si >> pi, s[i] = si, p[i++] = pi;

    std::ranges::sort(
        fav_strs,
        [](const auto &lhs, const auto &rhs) { return lhs.second > rhs.second; }
    );

    std::vector<std::pair<int, char>> counts(CHAR_NUM);
    for (int i = 0; i < CHAR_NUM; i++) counts[i] = {0, 'a' + i};
    for (const auto &si : s) {
        for (const auto &c : si) counts[c - 'a'].first++;
    }
    std::ranges::sort(
        counts,
        [](const auto &lhs, const auto &rhs) { return lhs.first > rhs.first; }
    );

    std::pair<int, std::vector<std::vector<int>>> result;
    std::string chars;
    for (int i = 0; i < 3; i++) {
        std::string ans_chars = fav_strs[i].first;
        for (int j = fav_strs[i].first.size(), k = 0; j < m; j++, k++) ans_chars += counts[j % CHAR_NUM].second;

        std::vector ans_matrix(m, std::vector<int>(m));
        for (size_t i = 0; i < fav_strs[0].first.size() - 1; i++) ans_matrix[i][i + 1] = 100;
        ans_matrix[fav_strs[0].first.size() - 1][0] = 100;
        for (int i = fav_strs[0].first.size(); i < m; i++) ans_matrix[i][i] = 100;

        chatgpt::Annealer annealer(s, p, ans_chars, ans_matrix);
        annealer.run();
        if (annealer.get_result().first > result.first) {
            result = annealer.get_result();
            chars = ans_chars;
        }
    }

    for (int i = 0; i < m; i++) {
        std::cout << chars[i] << ' ';
        for (int j = 0; j < m; j++) {
            std::cout << result.second[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << std::flush;
    return 0;
}
