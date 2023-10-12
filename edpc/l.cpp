#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<std::vector<long>> dp(n + 1, std::vector<long>(n + 1));  // 区間[i,j)が切り出された数列での得点
    std::vector<std::vector<bool>> is_searched(n + 1, std::vector<bool>(n + 1));

    auto calc_score = [&](auto calc_score, int i, int j) -> long {
        if (i - j == 0) {
            return 0;
        }

        if (is_searched[i][j]) {
            return dp[i][j];
        }

        is_searched[i][j] = true;
        dp[i][j] = std::max(
            static_cast<long>(a[i]) - calc_score(calc_score, i + 1, j),
            static_cast<long>(a[j - 1]) - calc_score(calc_score, i, j - 1)
        );

        return dp[i][j];
    };

    std::cout << calc_score(calc_score, 0, n) << std::endl;
    return 0;
}