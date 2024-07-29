#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    constexpr int INF = 1e9;

    int n, x, y;
    std::cin >> n >> x >> y;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) std::cin >> a[i] >> b[i];

    // dp[i][j][k] = i番目まで見て、j個食べ、甘さの最小値がkの時のしょっぱさの最小値
    int k_max = x + *std::ranges::max_element(a);
    std::vector dp(n, std::vector(n + 1, std::vector<int>(k_max + 1, INF)));
    dp[0][0][0] = 0;
    dp[0][1][a[0]] = b[0];

    int ans = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= k_max; k++) {
                dp[i][j][k] = std::min(dp[i][j][k], dp[i - 1][j][k]);

                if (k - a[i] < 0 || j - 1 < 0) continue;

                dp[i][j][k] = std::min(dp[i][j][k], dp[i - 1][j - 1][k - a[i]] + b[i]);
                if (k <= x && dp[i][j][k] <= y) {
                    ans = std::max(ans, std::min(j + 1, n));
                }
            }
        }
    }

    std::cout << ans << std::endl;
    return 0;
}