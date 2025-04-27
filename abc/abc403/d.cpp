#include <iostream>
#include <vector>

int main() {
    constexpr int A_MAX = 1e6 + 1;

    int n, d;
    std::cin >> n >> d;

    std::vector<int> a(n);
    std::vector<int> cnts(A_MAX + 1);
    for (auto &ai : a) std::cin >> ai, cnts[ai]++;

    if (d == 0) {
        int ans = 0;
        for (int i = 0; i < A_MAX; i++) {
            if (cnts[i] >= 2) ans += cnts[i] - 1;
        }
        std::cout << ans << std::endl;
        return 0;
    }

    int ans = 0;
    for (int i = 0; i < A_MAX; i++) {
        std::vector<int> group;
        if (cnts[i] == 0) continue;
        for (int j = i; j < A_MAX; j += d) {
            if (cnts[j] == 0) break;
            group.push_back(cnts[j]);
            cnts[j] = 0;
        }
        std::vector dp(group.size(), std::vector<int>(2));
        dp[0][true] = group[0], dp[0][false] = 0;
        for (size_t j = 1; j < group.size(); j++) {
            dp[j][true] = std::min(dp[j - 1][true], dp[j - 1][false]) + group[j];
            dp[j][false] = dp[j - 1][true];
        }
        ans += std::min(dp.back()[true], dp.back()[false]);
    }

    std::cout << ans << std::endl;
    return 0;
}