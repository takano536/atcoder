#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }

    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(2));
    dp[0][0] = 0;
    dp[0][1] = -1;

    for (int i = 1; i <= n; i++) {
        if (x[i - 1] == 0) {
            dp[i][0] = std::max(std::max(dp[i - 1][0], dp[i - 1][1]) + y[i - 1], dp[i - 1][0]);
            dp[i][1] = dp[i - 1][1];
        }
        if (x[i - 1] == 1) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = std::max(dp[i - 1][0] + y[i - 1], dp[i - 1][1]);
        }
    }

    std::cout << std::max(dp[n][0], dp[n][1]) << std::endl;
    return 0;
}