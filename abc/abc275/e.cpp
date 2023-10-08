#include <iostream>
#include <vector>

#include <atcoder/modint>

int main() {
    using modint = atcoder::modint998244353;

    int n, m, k;
    std::cin >> n >> m >> k;

    const modint M_INV = modint(m).inv();

    std::vector<std::vector<modint>> dp(k + 1, std::vector<modint>(n + 1));  // dp[i][j] = i回操作してjマスに到達する確率
    dp[0][0] = 1;
    for (int cnt = 1; cnt <= k; cnt++) {
        for (int curr_cell = 0; curr_cell < n; curr_cell++) {
            for (int dice = 1; dice <= m; dice++) {
                int next_cell = curr_cell + dice > n ? n - (curr_cell + dice - n) : curr_cell + dice;
                dp[cnt][next_cell] += dp[cnt - 1][curr_cell] * M_INV;
            }
        }
    }

    modint ans;
    for (int i = 0; i <= k; i++) {
        ans += dp[i][n];
    }

    std::cout << ans.val() << std::endl;
}