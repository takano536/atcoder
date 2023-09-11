#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, x;
    std::cin >> n >> x;

    std::vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i] >> b[i];
    }

    // dp[i][j] = i番目までの硬貨で合計がj円になるか
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(x + 1));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            for (int using_cnt = 0; using_cnt <= b[i]; using_cnt++) {
                if (j + a[i] * using_cnt > x || !dp[i - 1][j]) {
                    continue;
                }
                dp[i][j + a[i] * using_cnt] = true;
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        if (dp[i][x]) {
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }

    std::cout << "No" << std::endl;
    return 0;
}