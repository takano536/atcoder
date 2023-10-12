#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> x(n), y(n), z(n);
    int z_sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i] >> z[i];
        z_sum += z[i];
    }

    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(z_sum + 1, -1));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= z_sum; j++) {
            if (dp[i - 1][j] < 0) {
                continue;
            }
            if (x[i - 1] > y[i - 1]) {
                dp[i][j + z[i - 1]] = dp[i - 1][j];
            } else {
                if (dp[i][j] > -1) {
                    dp[i][j] = std::min(dp[i][j], dp[i - 1][j]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
                dp[i][j + z[i - 1]] = dp[i - 1][j] + (x[i - 1] + y[i - 1] + 1) / 2 - x[i - 1];
            }
        }
    }

    long long ans = 1e18;
    for (int i = 0; i <= n; i++) {
        for (int j = (z_sum + 1) / 2; j <= z_sum; j++) {
            if (dp[i][j] < 0) {
                continue;
            }
            ans = std::min(ans, dp[i][j]);
        }
    }
    std::cout << ans << std::endl;
    return 0;
}