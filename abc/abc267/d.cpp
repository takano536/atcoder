#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    const long long NA = -8e18;
    std::vector dp(n, std::vector<long long>(m, NA));
    dp[0][0] = a[0];

    long long ans = NA;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = std::max<long long>(a[i], dp[i][j]);
            if (dp[i - 1][j] != NA) dp[i][j] = std::max(dp[i - 1][j], dp[i][j]);
            if (j > 0 && dp[i - 1][j - 1] != NA) dp[i][j] = std::max(dp[i - 1][j - 1] + static_cast<long long>(a[i]) * (j + 1), dp[i][j]);
            if (j == m - 1) ans = std::max(dp[i][j], ans);
        }
    }

    std::cout << ans << std::endl;
    return 0;
}