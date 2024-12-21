#include <iostream>
#include <vector>

int main() {
    constexpr int MAX_H = 3000;

    int n;
    std::cin >> n;

    std::vector<int> h(n);
    for (auto &hi : h) std::cin >> hi;

    // dp[i][j] = 最後に選んだビルのindexがiで、indexの公差がjのときの最大値
    std::vector dp(n, std::vector<int>(MAX_H, 1));

    int ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= i; j++) {
            auto prev_i = i - j;
            if (h[prev_i] != h[i]) continue;
            dp[i][j] = dp[prev_i][j] + 1;
            ans = std::max(ans, dp[i][j]);
        }
    }

    std::cout << ans << std::endl;
    return 0;
}