#include <iostream>
#include <vector>

int main() {
    constexpr int NA = -1;

    int n, d;
    long long k;
    std::cin >> n >> k >> d;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    std::vector dp(n, std::vector(k, std::vector<long long>(d, NA)));
    dp[0][0][a[0] % d] = a[0];

    for (int i = 1; i < n; i++) {
        dp[i][0][a[i] % d] = std::max<long long>(a[i], dp[i][0][a[i] % d]);
        for (int j = 0; j < k; j++) {
            for (long long l = 0; l < d; l++) {
                dp[i][j][l] = std::max(dp[i - 1][j][l], dp[i][j][l]);
                if (j - 1 >= 0 && dp[i - 1][j - 1][l] != NA) {
                    dp[i][j][(l + a[i]) % d] = std::max(dp[i - 1][j - 1][l] + a[i], dp[i][j][(l + a[i]) % d]);
                }
            }
        }
    }

    std::cout << dp[n - 1][k - 1][0] << std::endl;
    return 0;
}