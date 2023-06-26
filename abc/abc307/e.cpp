#include <iostream>
#include <vector>

#include <atcoder/modint>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<atcoder::modint998244353>> dp(n, std::vector<atcoder::modint998244353>(2));
    dp[0][false] = 0;
    dp[0][true] = m;

    for (int i = 1; i < n; i++) {
        dp[i][false] += dp[i - 1][true] * (m - 1) + dp[i - 1][false] * ((m - 1) - 1);
        dp[i][true] += dp[i - 1][false];
    }

    std::cout << dp[n - 1][false].val() << std::endl;
    return 0;
}