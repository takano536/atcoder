#include <iostream>
#include <utility>
#include <vector>

int main() {
    constexpr int INF = 1 << 30;

    int n, m, diff;
    std::cin >> n >> m >> diff;

    std::vector<std::pair<int, int>> towns(n);
    for (auto &[a, b] : towns) std::cin >> a >> b;

    std::vector dp(n + 1, std::vector<long long>(m + 1, -INF));
    for (int i = 0; i <= n; i++) dp[i][0] = 0;

    long long ans = -INF;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= std::min(i + diff, n); j++) {
            for (int k = 0; k <= m; k++) {
                const auto &[v, c] = towns[j - 1];
                if (k + c > m) continue;
                dp[j][k + c] = std::max(static_cast<long long>(dp[i][k]) + v, dp[j][k + c]);
                ans = std::max(dp[j][k + c], ans);
            }
        }
    }

    std::cout << ans << std::endl;
    return 0;
}