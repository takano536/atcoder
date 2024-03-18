#include <iostream>
#include <numeric>
#include <vector>

#include <atcoder/modint>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector graph(n, std::vector<int>());
    for (int i = 0; i < n; i++) {
        graph[i].push_back(i);
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    std::vector dp(k + 1, std::vector<atcoder::modint>(n));
    dp[0][0] = 1;
    atcoder::modint prev_sum;
    for (int i = 1; i <= k; i++, prev_sum = 0) {
        for (int j = 0; j < n; j++) {
            prev_sum += dp[i - 1][j];
        }
        for (int j = 0; j < n; j++) {
            dp[i][j] = prev_sum;
            for (const auto &u : graph[j]) {
                dp[i][j] -= dp[i - 1][u];
            }
        }
    }

    std::cout << dp[k][0].val() << std::endl;
    return 0;
}