#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> costs(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int d;
            std::cin >> d;
            costs[i][j] = d;
            costs[j][i] = d;
        }
    }

    std::vector<long long> dp(1 << n);
    for (int bit = 0; bit < (1 << n); bit++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((bit & (1 << i)) || (bit & (1 << j))) {
                    continue;
                }
                int idx = bit | (1 << i) | (1 << j);
                dp[idx] = std::max(dp[idx], dp[bit] + costs[i][j]);
            }
        }
    }

    std::cout << dp[(1 << n) - 1] << std::endl;
}