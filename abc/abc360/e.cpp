#include <iostream>
#include <vector>

#include <atcoder/modint>

int main() {
    int n, k;
    std::cin >> n >> k;

    if (n == 1) {
        std::cout << 1 << std::endl;
        return 0;
    }

    const atcoder::modint N = n;
    const atcoder::modint K = k;

    const auto INV = N.pow(2).inv();

    std::vector dp(K.val() + 1, std::vector<atcoder::modint>(2));
    dp[0][0] = 1, dp[0][1] = 0;

    for (int i = 1; i <= static_cast<int>(K.val()); i++) {
        dp[i][0] += dp[i - 1][0] * (N.pow(2) - (N - 1) * 2) * INV;
        dp[i][0] += dp[i - 1][1] * (N - 1) * 2 * INV;
        dp[i][1] = (1 - dp[i][0]) / (N - 1);
    }

    std::cout << (dp[K.val()][0] + dp[K.val()][1] * (N + 2) * (N - 1) / 2).val() << std::endl;
    return 0;
}
