#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    constexpr int INF = 1e9;

    auto rle = [](const std::string &s) {
        std::vector<std::pair<char, int>> res;
        for (const auto &c : s) {
            if (res.empty() || res.back().first != c) {
                res.emplace_back(c, 1);
                continue;
            }
            res.back().second++;
        }
        return res;
    };

    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;

        auto encorded_s = rle(s);

        std::vector dp(encorded_s.size() + 1, std::vector<int>(3, INF));
        for (int j = 0; j < 3; j++) dp[0][j] = 0;

        for (size_t i = 1; i <= encorded_s.size(); i++) {
            const auto [c, len] = encorded_s[i - 1];
            for (int j = 0; j < 3; j++) {
                const auto min_cost = *std::min_element(dp[i - 1].begin(), std::next(dp[i - 1].begin(), j + 1));
                const int curr_cost = (c != (j == 1 ? '1' : '0') ? len : 0);
                dp[i][j] = min_cost + curr_cost;
            }
        }
        std::cout << *std::ranges::min_element(dp[encorded_s.size()]) << std::endl;
    }
    return 0;
}