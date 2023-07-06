#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> h(n);
    for (auto &input : h) {
        std::cin >> input;
    }

    std::vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        dp[i + 1] = std::min(dp[i] + std::abs(h[i] - h[i + 1]), dp[i + 1]);
        dp[i + 2] = std::min(dp[i] + std::abs(h[i] - h[i + 2]), dp[i + 2]);
    }

    std::cout << dp[n - 1] << std::endl;
    return 0;
}