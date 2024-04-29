#include <iostream>
#include <vector>

#include <atcoder/modint>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    // dp[i][j] = a_i=jとしたときの数列の総数の累積和
    std::vector dp(n, std::vector<atcoder::modint>(m + 1));
    for (int i = 1; i <= m; i++) {
        dp[0][i] = 1;
    }

    atcoder::modint cnt;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i - 1][j] += dp[i - 1][j - 1];
        }
        for (int j = 1; j <= m; j++) {
            cnt = 0;
            if (j - k > 0) {
                cnt += dp[i - 1][j - k];
            }
            if (j + k <= m) {
                cnt += dp[i - 1][m] - dp[i - 1][j + k - 1];
            }
            if (k == 0) {
                cnt -= dp[i - 1][j] - dp[i - 1][j - 1];
            }
            dp[i][j] = cnt;
        }
    }

    atcoder::modint ans;
    for (int i = 1; i <= m; i++) {
        ans += dp[n - 1][i];
    }
    std::cout << ans.val() << std::endl;
    return 0;
}