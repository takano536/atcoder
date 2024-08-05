#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    std::map<char, char> WINNABLE_HANDS = {
        {'R', 'P'},
        {'P', 'S'},
        {'S', 'R'},
    };
    std::map<char, std::array<char, 2>> TRANSFERABLE_HANDS = {
        {'R', {'P', 'S'}},
        {'P', {'S', 'R'}},
        {'S', {'R', 'P'}},
    };

    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector dp(n, std::map<char, int>());
    dp[0][s[0]] = 0;
    dp[0][WINNABLE_HANDS.at(s[0])] = 1;

    auto is_transferable = [&TRANSFERABLE_HANDS](const char hand, const std::map<char, int> &prev) {
        for (const char transferable_hand : TRANSFERABLE_HANDS[hand]) {
            if (prev.contains(transferable_hand)) return true;
        }
        return false;
    };

    auto transition = [&TRANSFERABLE_HANDS, &is_transferable](std::vector<std::map<char, int>> &dp, int i, const char hand, bool is_win) {
        if (!is_transferable(hand, dp[i - 1])) return;

        int prev_max = 0;
        const auto transferable_hands = TRANSFERABLE_HANDS[hand];
        for (const auto &[k, v] : dp[i - 1]) {
            if (std::ranges::find(transferable_hands, k) != transferable_hands.end()) {
                prev_max = std::max(prev_max, v);
            }
            dp[i][hand] = prev_max + (is_win ? 1 : 0);
        }
    };

    for (int i = 1; i < n; i++) {
        transition(dp, i, WINNABLE_HANDS[s[i]], true);
        transition(dp, i, s[i], false);
    }

    int ans = 0;
    for (const auto &[_, v] : dp[n - 1]) ans = std::max(ans, v);
    std::cout << ans << std::endl;
    return 0;
}