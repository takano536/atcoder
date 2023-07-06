#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i] >> c[i];
    }

    std::vector<std::vector<int>> dp(n, std::vector<int>(3));
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];

    for (int i = 1; i < n; i++) {
        dp[i][0] = std::max(dp[i - 1][1], dp[i - 1][2]) + a[i];
        dp[i][1] = std::max(dp[i - 1][0], dp[i - 1][2]) + b[i];
        dp[i][2] = std::max(dp[i - 1][0], dp[i - 1][1]) + c[i];
    }

    std::cout << std::max(std::max(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]) << std::endl;
    return 0;
}