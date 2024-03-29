#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#include <atcoder/modint>

int main() {
    int n;
    std::cin >> n;

    std::vector dp(n, std::vector<atcoder::modint>(10));
    std::ranges::fill(dp[0], 1);
    dp[0][0] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= 9; j++) {
            dp[i][j] += dp[i - 1][j];
            if (j - 1 >= 1) {
                dp[i][j] += dp[i - 1][j - 1];
            }
            if (j + 1 <= 9) {
                dp[i][j] += dp[i - 1][j + 1];
            }
        }
    }

    std::cout << std::accumulate(dp[n - 1].begin(), dp[n - 1].end(), atcoder::modint()).val() << std::endl;
    return 0;
}