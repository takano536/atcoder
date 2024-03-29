#include <iostream>
#include <vector>

#include <atcoder/modint>

int main() {
    int n, m, k, s, t, x;
    std::cin >> n >> m >> k >> s >> t >> x;
    s--, t--, x--;
    std::vector graph(n, std::vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // dp[i番目まで決めた][末尾がの番号がj][false:xが奇数回,true:xが偶数回]=数列の数
    std::vector dp(k + 1, std::vector(n, std::vector<atcoder::modint>(2)));
    dp[0][s][true] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i - 1][j][false] == 0 && dp[i - 1][j][true] == 0) {
                continue;
            }
            for (const auto &to : graph[j]) {
                if (to == x) {
                    dp[i][to][false] += dp[i - 1][j][true];
                    dp[i][to][true] += dp[i - 1][j][false];
                } else {
                    dp[i][to][true] += dp[i - 1][j][true];
                    dp[i][to][false] += dp[i - 1][j][false];
                }
            }
        }
    }
    std::cout << dp[k][t][true].val() << std::endl;
    return 0;
}