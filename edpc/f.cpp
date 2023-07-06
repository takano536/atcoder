#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s, t;
    std::cin >> s >> t;

    int s_len = s.size();
    int t_len = t.size();

    std::vector<std::vector<int>> dp(s_len + 1, std::vector<int>(t_len + 1));
    for (int i = 1; i <= s_len; i++) {
        for (int j = 1; j <= t_len; j++) {
            dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = std::max(dp[i - 1][j - 1] + 1, dp[i][j]);
            }
        }
    }

    std::string ans;
    int i = s_len, j = t_len;
    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i][j - 1]) {
            j--;
        } else if (dp[i][j] == dp[i - 1][j]) {
            i--;
        } else if (dp[i][j] - 1 == dp[i - 1][j - 1]) {
            i--, j--;
            ans = s[i] + ans;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}