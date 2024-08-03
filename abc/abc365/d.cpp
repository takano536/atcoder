#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    std::map<char, int> HANDS = {{'R', 0}, {'S', 1}, {'P', 2}};
    constexpr int NA = -1;

    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector dp(n, std::vector<int>(3, NA));
    switch (s[0]) {
        case 'S':
            dp[0][HANDS['R']] = 1;
            dp[0][HANDS['S']] = 0;
            break;
        case 'R':
            dp[0][HANDS['P']] = 1;
            dp[0][HANDS['R']] = 0;
            break;
        case 'P':
            dp[0][HANDS['S']] = 1;
            dp[0][HANDS['P']] = 0;
            break;
    }

    int ans = 1;
    for (int i = 1; i < n; i++) {
        const auto aoki = s[i];
        switch (aoki) {
            case 'S':
                if (dp[i - 1][HANDS['S']] != NA || dp[i - 1][HANDS['P']] != NA) {
                    dp[i][HANDS['R']] = std::max(dp[i - 1][HANDS['S']], dp[i - 1][HANDS['P']]) + 1;
                }
                if (dp[i - 1][HANDS['P']] != NA || dp[i - 1][HANDS['R']] != NA) {
                    dp[i][HANDS['S']] = std::max(dp[i - 1][HANDS['P']], dp[i - 1][HANDS['R']]);
                }
                ans = std::max(ans, dp[i][HANDS['R']]);
                ans = std::max(ans, dp[i][HANDS['S']]);
                break;
            case 'R':
                if (dp[i - 1][HANDS['R']] != NA || dp[i - 1][HANDS['S']] != NA) {
                    dp[i][HANDS['P']] = std::max(dp[i - 1][HANDS['R']], dp[i - 1][HANDS['S']]) + 1;
                }
                if (dp[i - 1][HANDS['P']] != NA || dp[i - 1][HANDS['S']] != NA) {
                    dp[i][HANDS['R']] = std::max(dp[i - 1][HANDS['P']], dp[i - 1][HANDS['S']]);
                }
                ans = std::max(ans, dp[i][HANDS['P']]);
                ans = std::max(ans, dp[i][HANDS['R']]);
                break;
            case 'P':
                if (dp[i - 1][HANDS['P']] != NA || dp[i - 1][HANDS['R']] != NA) {
                    dp[i][HANDS['S']] = std::max(dp[i - 1][HANDS['P']], dp[i - 1][HANDS['R']]) + 1;
                }
                if (dp[i - 1][HANDS['R']] != NA || dp[i - 1][HANDS['S']] != NA) {
                    dp[i][HANDS['P']] = std::max(dp[i - 1][HANDS['R']], dp[i - 1][HANDS['S']]);
                }
                ans = std::max(ans, dp[i][HANDS['S']]);
                ans = std::max(ans, dp[i][HANDS['P']]);
                break;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}