#include <iostream>
#include <utility>
#include <vector>

int main() {
    int n, h, m;
    std::cin >> n >> h >> m;

    std::vector<std::pair<int, int>> monsters(n);
    for (auto &[a, b] : monsters) std::cin >> a >> b;

    std::vector dp(n + 1, std::vector<int>(h + 1));
    dp[0][h] = m;

    for (int i = 1; i <= n; i++) {
        const auto [hi, mi] = monsters[i - 1];
        bool is_defeatable = false;
        for (int j = 0; j <= h; j++) {
            if (dp[i - 1][j] == 0) continue;
            if (j - hi >= 0) {
                dp[i][j - hi] = std::max(dp[i - 1][j], dp[i][j - hi]);
                is_defeatable = true;
            }
            if (dp[i - 1][j] - mi >= 0) {
                dp[i][j] = std::max(dp[i - 1][j] - mi, dp[i][j]);
                is_defeatable = true;
            }
        }
        if (is_defeatable) continue;

        std::cout << i - 1 << std::endl;
        return 0;
    }

    std::cout << n << std::endl;
    return 0;
}