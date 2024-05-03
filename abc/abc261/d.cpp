#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> x(n);
    for (auto &xi : x) std::cin >> xi;

    std::map<int, int> bonuses;
    for (int i = 0; i < m; i++) {
        int c, y;
        std::cin >> c >> y;
        bonuses[c] = y;
    }

    const int NA = -1;
    std::vector dp(n + 1, std::vector<long long>(n + 1, NA));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i - 1][j - 1] == NA) continue;
            dp[i][j] = std::max(dp[i - 1][j - 1] + x[i - 1] + (bonuses.contains(j) ? bonuses[j] : 0), dp[i][j]);
            dp[i][0] = std::max(dp[i - 1][j - 1], dp[i][0]);
        }
    }

    std::cout << *std::ranges::max_element(dp[n]) << std::endl;
    return 0;
}