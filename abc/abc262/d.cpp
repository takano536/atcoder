#include <iostream>
#include <vector>

#include <atcoder/modint>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    atcoder::modint ans = n;
    for (int mult = 2; mult <= n; mult++) {
        std::vector dp(n, std::vector(n + 1, std::vector<atcoder::modint>(n)));
        dp[0][0][0]++;
        dp[0][1][a[0] % mult]++;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k < mult; k++) {
                    if (dp[i - 1][j][k] == 0) continue;
                    dp[i][j][k] += dp[i - 1][j][k];
                    dp[i][j + 1][(k + a[i]) % mult] += dp[i - 1][j][k];
                }
                if (i == n - 1 && j == mult) ans += dp[n - 1][j][0];
            }
        }
    }

    std::cout << ans.val() << std::endl;
    return 0;
}