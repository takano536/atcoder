#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

#include <atcoder/modint>

int main() {
    using modint = atcoder::modint998244353;
    const int TARGET_IDX = 0;

    int n, x;
    std::cin >> n >> x;
    const modint N_INV = modint(1) / n;

    std::vector<int> t(n);
    for (int i = 0; i < n; i++) {
        std::cin >> t[i];
    }

    std::vector<modint> dp(x + t[TARGET_IDX] + 1);  // dp[i] = 時刻iで曲の再生が終わる確率
    dp[0] = 1;

    for (int i = 0; i <= x + t[TARGET_IDX]; i++) {
        for (int j = 0; j < n; j++) {
            if (i - t[j] < 0) {
                continue;
            }
            if (dp[i - t[j]].val() == 0) {
                continue;
            }
            dp[i] += dp[i - t[j]] * N_INV;
        }
    }

    modint ans = 0;
    for (int i = std::max(0, x - t[TARGET_IDX] + 1); i <= x; i++) {
        ans += dp[i] * N_INV;
    }

    std::cout << ans.val() << std::endl;
    return 0;
}