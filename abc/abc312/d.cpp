#include <iostream>
#include <string>
#include <vector>

#include <atcoder/modint>

int main() {
    using mint = atcoder::modint998244353;

    std::string s;
    std::cin >> s;

    int n = s.size();

    std::vector<std::vector<mint>> dp(n + 1, std::vector<mint>(n + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (dp[i - 1][j].val() == 0) {
                continue;
            }
            if (s[i - 1] == '?') {
                if (j + 1 <= n) {
                    dp[i][j + 1] += dp[i - 1][j];
                }
                if (j - 1 >= 0) {
                    dp[i][j - 1] += dp[i - 1][j];
                }
            }
            if (s[i - 1] == '(' && j + 1 <= n) {
                dp[i][j + 1] += dp[i - 1][j];
            }
            if (s[i - 1] == ')' && j - 1 >= 0) {
                dp[i][j - 1] += dp[i - 1][j];
            }
        }
    }

    std::cout << dp[n][0].val() << std::endl;
    return 0;
}