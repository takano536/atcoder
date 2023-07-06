#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> h(n);
    for (auto &input : h) {
        std::cin >> input;
    }

    std::vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i + j >= n) {
                continue;
            }
            dp[i + j] = std::min(dp[i] + std::abs(h[i] - h[i + j]), dp[i + j]);
        }
    }

    std::cout << dp[n - 1] << std::endl;
    return 0;
}