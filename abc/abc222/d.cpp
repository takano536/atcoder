#include <algorithm>
#include <iostream>
#include <vector>

#include <atcoder/modint>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (auto &ai : a) {
        std::cin >> ai;
    }
    for (auto &bi : b) {
        std::cin >> bi;
    }

    const int max_num = *std::ranges::max_element(b);

    std::vector dp(n, std::vector<atcoder::modint>(max_num + 1 + 1, 0));  // 累積和
    for (int i = a[0]; i <= max_num; i++) {
        if (i <= b[0]) {
            dp[0][i + 1] = 1;
        }
        if (i != a[0]) {
            dp[0][i + 1] += dp[0][i];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = a[i]; j <= max_num; j++) {
            if (j <= b[i]) {
                dp[i][j + 1] = dp[i - 1][j + 1] - dp[i - 1][0];
            }
            if (j != a[i]) {
                dp[i][j + 1] += dp[i][j];
            }
        }
    }

    std::cout << dp[n - 1][max_num + 1].val() << std::endl;
    return 0;
}