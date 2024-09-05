#include <iostream>
#include <vector>

int main() {
    constexpr int MAX_POW = 60;
    constexpr int MAX_N = 1e5 - 1;
    constexpr int MOD = 1e5;

    int n;
    long long k;
    std::cin >> n >> k;

    auto push_a = [&](const int x) {
        int y = 0;
        for (const auto &c : std::to_string(x)) y += static_cast<int>(c - '0');
        const int z = (x + y) % MOD;
        return z;
    };

    std::vector dp(MAX_POW, std::vector<int>(MAX_N + 1));
    for (int i = 0; i <= MAX_N; i++) dp[0][i] = push_a(i);

    for (int i = 1; i < MAX_POW; i++) {
        for (int j = 0; j <= MAX_N; j++) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }

    int ans = n;
    for (int i = 0; i < MAX_POW; i++) {
        if (k & (1LL << i)) ans = dp[i][ans];
    }
    std::cout << ans << std::endl;
    return 0;
}