#include <iostream>
#include <utility>
#include <vector>

int main() {
    constexpr int INF = 1e9;

    int h, n;
    std::cin >> h >> n;

    std::vector<std::pair<int, int>> spells(n);
    for (auto &[a, b] : spells) std::cin >> a >> b;

    std::vector dp(n + 1, std::vector(h + 1, INF));
    for (int i = 0; i <= n; i++) dp[i][h] = 0;

    for (int i = 1; const auto &[a, b] : spells) {
        for (int j = h; j >= 0; j--) {
            dp[i][std::max(0, j - a)] = std::min(dp[i][j] + b, dp[i][std::max(0, j - a)]);
            if (i + 1 < n + 1) dp[i + 1][j] = std::min(dp[i][j], dp[i + 1][j]);
        }
        i++;
    }

    std::cout << dp[n][0] << std::endl;
    return 0;
}