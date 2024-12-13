#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    // '.'=0, '#'=1
    std::vector dp(n, std::vector<int>(2));
    if (s[0] == '.') {
        dp[0][0] = 0;
        dp[0][1] = 1;
    } else {
        dp[0][0] = 1;
        dp[0][1] = 0;
    }

    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + (s[i] == '.' ? 0 : 1);
        dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][1]) + (s[i] == '#' ? 0 : 1);
    }

    std::cout << std::min(dp[n - 1][0], dp[n - 1][1]) << std::endl;
    return 0;
}