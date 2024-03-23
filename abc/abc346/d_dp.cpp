#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::string s_str;
    std::cin >> s_str;
    std::vector<long long> c(n);
    for (auto &ci : c) {
        std::cin >> ci;
    }

    std::vector<int> s(n);
    for (int i = 0; i < n; i++) {
        s[i] = s_str[i] - '0';
    }

    const long long INF = 1e18;
    std::vector dp(n, std::vector(2, std::vector<long long>(2, INF)));  // dp[何文字目か][直前の文字][良い文字列かどうか]=最小コスト
    dp[0][s[0]][0] = 0;
    dp[0][!s[0]][0] = c[0];

    for (int i = 1; i < n; i++) {
        dp[i][0][false] = dp[i - 1][1][false] + (s[i] == 0 ? 0 : c[i]);
        dp[i][1][false] = dp[i - 1][0][false] + (s[i] == 1 ? 0 : c[i]);
        dp[i][0][true] = std::min(dp[i - 1][0][false], dp[i - 1][1][true]) + (s[i] == 0 ? 0 : c[i]);
        dp[i][1][true] = std::min(dp[i - 1][1][false], dp[i - 1][0][true]) + (s[i] == 1 ? 0 : c[i]);
    }
    std::cout << std::min(dp[n - 1][0][true], dp[n - 1][1][true]) << std::endl;
}