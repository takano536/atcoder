#include <array>
#include <iostream>
#include <string>
#include <vector>

int main() {
    long long x, y, z;
    std::cin >> x >> y >> z;
    std::string s;
    std::cin >> s;

    int n = s.size();

    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(2, 1e18));
    dp[0][0] = 0;
    dp[0][1] = z;

    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == 'a') {
            dp[i][0] = std::min(std::min(dp[i - 1][0] + x, dp[i - 1][1] + z + x), dp[i][0]);
            dp[i][1] = std::min(std::min(dp[i - 1][1] + y, dp[i - 1][0] + z + y), dp[i][1]);
        }
        if (s[i - 1] == 'A') {
            dp[i][1] = std::min(std::min(dp[i - 1][1] + x, dp[i - 1][0] + z + x), dp[i][1]);
            dp[i][0] = std::min(std::min(dp[i - 1][0] + y, dp[i - 1][1] + z + y), dp[i][0]);
        }
    }

    std::cout << std::min(dp[n][0], dp[n][1]) << std::endl;
}