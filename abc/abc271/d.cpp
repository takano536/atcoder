#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
    constexpr int S_MAX = 10000;
    constexpr int NA = 0;
    constexpr int FRONT = 1;
    constexpr int BACK = -1;

    int n, s;
    std::cin >> n >> s;

    std::vector<std::pair<int, int>> cards(n);
    for (auto &[a, b] : cards) std::cin >> a >> b;

    std::vector dp(n, std::vector<int>(S_MAX + 1, NA));
    dp[0][cards[0].first] = FRONT;
    dp[0][cards[0].second] = BACK;

    for (int i = 1; i < n; i++) {
        const auto [front_num, back_num] = cards[i];
        for (int j = 1; j <= S_MAX; j++) {
            if (dp[i - 1][j] == NA) continue;
            if (j + front_num <= S_MAX) dp[i][j + front_num] = FRONT;
            if (j + back_num <= S_MAX) dp[i][j + back_num] = BACK;
        }
    }

    if (dp[n - 1][s] == NA) {
        std::cout << "No" << std::endl;
        return 0;
    }

    std::string ans;
    int curr_sum = s;
    for (int i = n - 1; i >= 0; i--) {
        const auto [front_num, back_num] = cards[i];
        ans += (dp[i][curr_sum] == FRONT ? "H" : "T");
        curr_sum -= (dp[i][curr_sum] == FRONT ? front_num : back_num);
    }
    std::ranges::reverse(ans);

    std::cout << "Yes" << std::endl;
    std::cout << ans << std::endl;
    return 0;
}