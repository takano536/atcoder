#include <cmath>
#include <iostream>
#include <vector>
#include <cstdio>

int main() {
    int n;
    std::cin >> n;

    std::vector<double> p(n);
    for (auto &input : p) {
        std::cin >> input;
    }

    std::vector<std::vector<double>> dp(n + 1, std::vector<double>(n + 1));
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i + 1][j] += dp[i][j] * (1.0 - p[i]);
            dp[i + 1][j + 1] += dp[i][j] * p[i];
        }
    }

    double ans = 0;
    for (int i = n; i > ceil(n / 2); i--) {
        ans += dp[n][i];
    }

    std::printf("%.10f\n", ans);
}