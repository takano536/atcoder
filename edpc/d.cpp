#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, max_weight;
    std::cin >> n >> max_weight;

    std::vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i] >> v[i];
    }

    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(max_weight + 1, -1e18));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= max_weight; j++) {
            dp[i][j] = std::max(dp[i - 1][j], dp[i][j]);
            if (j - w[i - 1] >= 0) {
                dp[i][j] = std::max(dp[i - 1][j - w[i - 1]] + v[i - 1], dp[i][j]);
            }
        }
    }

    std::cout << *std::max_element(dp[n].begin(), dp[n].end()) << std::endl;
    return 0;
}