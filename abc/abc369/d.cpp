#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    std::vector dp(n, std::vector<long long>(2));
    dp[0][false] = a[0];
    dp[0][true] = 0;

    for (int i = 1; i < n; i++) {
        dp[i][false] = std::max(dp[i - 1][false], dp[i - 1][true] + a[i]);
        dp[i][true] = std::max(dp[i - 1][true], dp[i - 1][false] + a[i] + a[i]);
    }

    std::cout << std::max(dp[n - 1][false], dp[n - 1][true]) << std::endl;
    return 0;
}