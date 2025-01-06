#include <iostream>
#include <limits>
#include <vector>

int main() {
    constexpr long long INF = std::numeric_limits<long long>::max();

    int n, m;
    std::cin >> n >> m;

    std::vector<long long> a(n);
    for (auto &ai : a) std::cin >> ai;

    std::vector dp(n + 1, std::vector<long long>(m + 1, -INF));
    dp[0][0] = 0;

    long long ans = -INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] == -INF) continue;
            dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j]);
            dp[i + 1][j + 1] = std::max(dp[i][j] + a[i] * (j + 1), dp[i + 1][j + 1]);
            if (j + 1 == m) ans = std::max(dp[i + 1][j + 1], ans);
        }
    }

    std::cout << ans << std::endl;
    return 0;
}