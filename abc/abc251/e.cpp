#include <iostream>
#include <vector>

int main() {
    constexpr long long INF = 8e18;

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    long long ans = INF;

    std::vector<long long> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        if (i != 1) dp[i] = std::min(dp[i - 1] + a[i - 2], dp[i]);
        if (i != 1) dp[i] = std::min(dp[i - 2] + a[i - 2], dp[i]);
        dp[i + 1] = std::min(dp[i - 1] + a[i - 1], dp[i + 1]);
        dp[i + 1] = std::min(dp[i] + a[i - 1], dp[i + 1]);
    }
    ans = std::min(dp[n], ans);

    dp = std::vector(n + 1, INF);
    dp[0] = a[n - 1], dp[1] = a[n - 1];
    for (int i = 1; i < n; i++) {
        if (i != 1) dp[i] = std::min(dp[i - 1] + a[i - 2], dp[i]);
        if (i != 1) dp[i] = std::min(dp[i - 2] + a[i - 2], dp[i]);
        dp[i + 1] = std::min(dp[i - 1] + a[i - 1], dp[i + 1]);
        dp[i + 1] = std::min(dp[i] + a[i - 1], dp[i + 1]);
    }
    ans = std::min(std::min(dp[n - 1], dp[n]), ans);

    std::cout << ans << std::endl;
    return 0;
}