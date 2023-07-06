#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    const long long INF = 1e18;
    const int MAX_VALUE = 100 * 1e3;

    int n, max_weight;
    std::cin >> n >> max_weight;

    std::vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i] >> v[i];
    }

    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(MAX_VALUE + 1, INF));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= MAX_VALUE; j++) {

            dp[i][j] = std::min(dp[i - 1][j], dp[i][j]);

            if (j - v[i - 1] < 0) {
                continue;
            }
            if (dp[i - 1][j - v[i - 1]] == INF) {
                continue;
            }

            dp[i][j] = std::min(dp[i - 1][j - v[i - 1]] + w[i - 1], dp[i][j]);
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= MAX_VALUE; j++) {
            if (dp[i][j] > max_weight) {
                continue;
            }
            ans = std::max(j, ans);
        }
    }

    std::cout << ans << std::endl;
    return 0;
}