#include <algorithm>
#include <array>
#include <chrono>
#include <iostream>
#include <queue>
#include <random>
#include <tuple>
#include <utility>
#include <vector>

#include <cmath>
#include <cstring>
#include <sstream>
#include <string>

constexpr int MAX_N = 40;

namespace chatgpt {

using namespace std;

struct Input {
    int N;
    int M;
    array<array<char, MAX_N>, MAX_N> S;
};

struct State {
    array<array<char, MAX_N>, MAX_N> S;
    array<array<double, MAX_N>, MAX_N> prob;
    vector<double> lives;
};

const int di[4] = {-1, 1, 0, 0};
const int dj[4] = {0, 0, -1, 1};

tuple<long long, string, State> compute_score_details(
    const Input &input,
    const vector<pair<int, int>> &out
) {
    const int N = input.N;
    const int M = input.M;

    array<array<char, MAX_N>, MAX_N> S = input.S;
    array<array<double, MAX_N>, MAX_N> crt{};
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (input.S[i][j] == '.')
                crt[i][j] = 1.0 / static_cast<double>(N * N - M);

    double ret = 0.0;
    vector<double> lives;
    lives.push_back(1.0);
    double life = 1.0;

    for (int t = 0;; ++t) {
        array<array<double, MAX_N>, MAX_N> next{};
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (crt[i][j] == 0.0) continue;
                for (int d = 0; d < 4; ++d) {
                    int i2 = i, j2 = j;
                    while (true) {
                        int ni = i2 + di[d], nj = j2 + dj[d];
                        if (ni < 0 || ni >= N || nj < 0 || nj >= N || S[ni][nj] != '.')
                            break;
                        i2 = ni;
                        j2 = nj;
                    }
                    next[i2][j2] += crt[i][j] * 0.25;
                }
            }
        }

        crt = next;

        if (t >= static_cast<int>(out.size())) break;

        int bi = out[t].first;
        int bj = out[t].second;

        if (S[bi][bj] == '#') {
            ostringstream oss;
            oss << "(" << bi << ", " << bj << ") is already blocked (turn " << t << ")";
            return {
                0LL,
                oss.str(),
                State{S, crt, lives}};
        }

        life -= crt[bi][bj];
        crt[bi][bj] = 0.0;
        S[bi][bj] = '#';
        ret += life;
        lives.push_back(life);
    }

    double ub = static_cast<double>(N * N - M - 1);
    long long score = static_cast<long long>(round(ret / ub * 1e6));
    string err;

    if (out.size() < static_cast<size_t>(N * N - M)) {
        err = "Not finished";
    }

    return {
        score,
        err,
        State{S, crt, lives}};
}

pair<long long, string> compute_score(
    const Input &input,
    const vector<pair<int, int>> &out
) {
    auto [score, err, _] = compute_score_details(input, out);
    if (!err.empty()) {
        score = 0;
    }
    return {score, err};
}

}  // namespace chatgpt

int main() {
    constexpr int INF = 1e9;
    constexpr std::array DIRS = {
        std::make_pair(+1, 0),
        std::make_pair(0, +1),
        std::make_pair(-1, 0),
        std::make_pair(0, -1),
    };

    int _, m;
    std::cin >> _ >> m;

    std::array<std::array<char, MAX_N>, MAX_N> s;
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) std::cin >> s[i][j];
    }

    std::array<std::array<std::pair<int, int>, MAX_N>, MAX_N> reachable_counts;

    auto bfs = [&](const int &i, const int &j) {
        std::queue<std::pair<int, int>> que;
        que.emplace(i, j);
        std::array<std::array<bool, MAX_N>, MAX_N> has_visited;
        has_visited[i][j] = true;

        while (!que.empty()) {
            const auto [i, j] = que.front();
            que.pop();
            for (const auto &[di, dj] : DIRS) {
                int ni = i, nj = j;
                while (true) {
                    if (ni + di < 0 || ni + di >= MAX_N) break;
                    if (nj + dj < 0 || nj + dj >= MAX_N) break;
                    if (s[ni + di][nj + dj] == '#') break;
                    ni += di;
                    nj += dj;
                }
                reachable_counts[ni][nj].first++;
                if (has_visited[ni][nj]) continue;
                reachable_counts[ni][nj].second++;
                has_visited[ni][nj] = true;
                que.emplace(ni, nj);
            }
        }
    };

    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            if (s[i][j] == '#') {
                reachable_counts[i][j] = std::make_pair(INF, 0);
                continue;
            }
            bfs(i, j);
        }
    }

    std::array<std::tuple<int, int, int, int>, MAX_N * MAX_N> ans;
    int index = 0;
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++, index++) {
            const auto [total, unique] = reachable_counts[i][j];
            ans[index] = std::make_tuple(unique, total, i, j);
        }
    }
    std::ranges::sort(ans);

    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    chatgpt::Input input;
    input.N = MAX_N;
    input.M = m;
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) input.S[i][j] = s[i][j];
    }

    std::vector<std::pair<int, int>> out(MAX_N * MAX_N - m);
    index = 0;
    for (const auto &[unique, total, i, j] : ans) {
        if (total == INF) continue;
        out[index++] = std::make_pair(i, j);
    }

    auto [score, err] = chatgpt::compute_score(input, out);
    if (!err.empty()) {
        std::cerr << "Error: " << err << std::endl;
        return 1;
    }

    // 焼きなまし法の設定
    auto current_out = out;
    auto best_out = out;
    long long best_score = score;
    auto current_score = score;
    std::chrono::steady_clock::time_point time_start = std::chrono::steady_clock::now();
    double TIME_LIMIT = 1.9;  // 秒
    double start_temp = 1e3, end_temp = 1e-3;

    int n = static_cast<int>(current_out.size());
    std::mt19937 rng(std::random_device{}());

    for (int iter = 0;; ++iter) {
        auto now = std::chrono::steady_clock::now();
        double elapsed = std::chrono::duration<double>(now - time_start).count();
        if (elapsed > TIME_LIMIT) break;

        double temp = start_temp + (end_temp - start_temp) * (elapsed / TIME_LIMIT);

        int i = rng() % n;
        int j = rng() % n;
        if (i == j) continue;

        std::swap(current_out[i], current_out[j]);

        auto [new_score, err] = chatgpt::compute_score(input, current_out);
        if (!err.empty()) {
            std::swap(current_out[i], current_out[j]);  // 戻す
            continue;
        }

        long long delta = new_score - current_score;

        if (delta >= 0 || exp(delta / temp) > std::uniform_real_distribution<>(0.0, 1.0)(rng)) {
            current_score = new_score;
            if (new_score > best_score) {
                best_score = new_score;
                best_out = current_out;
            }
        } else {
            std::swap(current_out[i], current_out[j]);  // 戻す
        }
    }

    // 最良の順列に更新
    out = best_out;

    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    for (const auto &[i, j] : out) {
        std::cout << i << " " << j << std::endl;
    }
    std::cout << std::flush;
    // std::cerr << "Score: " << best_score << std::endl;

    return 0;
}