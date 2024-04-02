#include <iostream>
#include <vector>

#include <atcoder/modint>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector dp(n + 1, std::vector<atcoder::modint>(k + 1));  // dp[i][j]=i番目まで決めて合計がjとなるような数列の数
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int ai = 1; ai <= m; ai++) {
                if (j + ai <= k) {
                    dp[i][j + ai] += dp[i - 1][j];
                }
            }
        }
    }

    atcoder::modint ans;
    for (const auto &cnt : dp[n]) {
        ans += cnt;
    }
    std::cout << ans.val() << std::endl;
    return 0;
}