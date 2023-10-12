#include <iomanip>
#include <iostream>
#include <vector>

int main() {
    const int MAX_SUSHI_CNT = 3;

    int n;
    std::cin >> n;

    std::vector<int> cnts(MAX_SUSHI_CNT + 1);

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        cnts[a[i]]++;
    }

    const double INF = -1;
    std::vector<std::vector<std::vector<double>>> dp(
        n + 1, std::vector<std::vector<double>>(n + 1, std::vector<double>(n + 1, INF))
    );  // すし1つの皿がi枚、すし2つの皿がj枚、すし3の皿がk枚の状態から寿司をすべてなくなるまでの操作回数の期待値

    dp[0][0][0] = 0;
    auto get_exp = [&](auto get_exp, int i, int j, int k) -> double {
        if (i < 0 || j < 0 || k < 0) {
            return 0;
        }
        if (dp[i][j][k] != INF) {
            return dp[i][j][k];
        }

        double exp = 0;
        exp += get_exp(get_exp, i - 1, j, k) * i;
        exp += get_exp(get_exp, i + 1, j - 1, k) * j;
        exp += get_exp(get_exp, i, j + 1, k - 1) * k;
        exp += n;
        exp /= (i + j + k);

        dp[i][j][k] = exp;
        return exp;
    };

    std::cout << std::fixed << std::setprecision(10) << get_exp(get_exp, cnts[1], cnts[2], cnts[3]) << std::endl;
    return 0;
}