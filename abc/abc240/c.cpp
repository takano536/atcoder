#include <iostream>
#include <vector>

int main() {
    int n, x;
    std::cin >> n >> x;

    std::vector dp(n + 1, std::vector<bool>(x + 1));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        int a, b;
        std::cin >> a >> b;
        for (int j = 0; j < x + 1; j++) {
            if (dp[i - 1][j] == false) {
                continue;
            }
            if (j + a <= x) {
                dp[i][j + a] = true;
            }
            if (j + b <= x) {
                dp[i][j + b] = true;
            }
        }
    }

    std::cout << (dp[n][x] == true ? "Yes" : "No") << std::endl;
    return 0;
}