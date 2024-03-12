#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    int x, y;
    std::cin >> x >> y;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i];
    }

    const int INF = 1e9;
    int ans = INF;

    std::vector dp(n + 1, std::vector(x + 1, std::vector<int>(y + 1, INF)));
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            for (int k = 0; k <= y; k++) {
                dp[i][j][k] = std::min(dp[i][j][k], dp[i - 1][j][k]);
                int next_j = std::min(x, j + a[i - 1]);
                int next_k = std::min(y, k + b[i - 1]);
                dp[i][next_j][next_k] = std::min(dp[i][next_j][next_k], dp[i - 1][j][k] + 1);
                if (dp[i][next_j][next_k] != INF && next_j >= x && next_k >= y) {
                    ans = std::min(ans, dp[i][next_j][next_k]);
                }
            }
        }
    }

    std::cout << (ans != INF ? ans : -1) << std::endl;
    return 0;
}