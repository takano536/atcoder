#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<bool> exists(n + 1, true);
    std::vector<int> a(k);
    for (auto &ai : a) {
        std::cin >> ai;
        exists[ai] = false;
    }

    int ans = 0;
    if (k % 2 == 0) {

        const int num = 2 * n - k;
        std::vector<int> socks(num);
        for (int i = 0, color = 1; i < num; color++) {
            socks[i++] = color;
            if (exists[color]) socks[i++] = color;
        }
        int score = 0;
        for (int i = 0; i < num; i += 2) score += socks[i + 1] - socks[i];
        ans = score;

    } else {

        const int num = k / 2;
        std::vector<int> scores(num), rev_scores(num);
        for (int i = 0, sock_i = 0; i < num; i++, sock_i += 2) scores[i] = a[sock_i + 1] - a[sock_i];
        for (int i = 0, sock_i = k - 1; i < num; i++, sock_i -= 2) rev_scores[i] = a[sock_i] - a[sock_i - 1];

        std::vector<int> score_cumsum(num + 1), rev_score_cumsum(num + 1);
        for (int i = 0; i < num; i++) score_cumsum[i + 1] = score_cumsum[i] + scores[i];
        for (int i = 0; i < num; i++) rev_score_cumsum[i + 1] = rev_score_cumsum[i] + rev_scores[i];

        ans = std::min(score_cumsum[num], rev_score_cumsum[num]);
        for (int i = 0; i < num - 1; i++) {
            int score = 0;
            score += score_cumsum[i + 1];
            score += rev_score_cumsum[num - i - 1];
            ans = std::min(ans, score);
        }
    }

    std::cout << ans << std::endl;
    return 0;
}