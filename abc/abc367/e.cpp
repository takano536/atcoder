#include <iostream>
#include <vector>

int main() {
    constexpr int MAX_POW = 60;

    int n;
    long long k;
    std::cin >> n >> k;

    std::vector<int> x(n);
    for (auto &xi : x) {
        std::cin >> xi;
        xi--;
    }

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    std::vector dp(MAX_POW, std::vector<int>(n));
    for (int i = 0; i < n; i++) dp[0][i] = x[i];

    for (int i = 1; i < MAX_POW; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }

    for (int i = 0; i < n; i++) {
        int ans_i = i;
        for (int j = 0; j < MAX_POW; j++) {
            if (!(k & (1LL << j))) continue;
            ans_i = dp[j][ans_i];
        }
        std::cout << a[ans_i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}