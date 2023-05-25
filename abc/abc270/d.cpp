#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(m);
    for (auto &num : a) {
        std::cin >> num;
    }

    // 石がi個あり、手番がj(j=0:高橋君、j=1:青木君)の時に高橋君が取れる石の数の合計
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(2));
    for (int i = 1; i <= n; i++) {
        dp[i][1] = 1e9;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < m; k++) {
                if (i - a[k] < 0) {
                    continue;
                }
                if (j == 0) {
                    // 高橋君の番
                    dp[i][j] = std::max(a[k] + dp[i - a[k]][1], dp[i][j]);
                } else {
                    // 青木君の番
                    dp[i][j] = std::min(dp[i - a[k]][0], dp[i][j]);
                }
            }
        }
    }

    std::cout << dp[n][0] << std::endl;
    return 0;
}