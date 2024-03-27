#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string t;
    std::cin >> t;
    int t_len = t.size();
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<std::vector<std::string>> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        for (int j = 0; j < a[i]; j++) {
            std::string str;
            std::cin >> str;
            s[i].push_back(str);
        }
    }

    const int INF = 1e9;
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(t_len + 1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (const auto &si : s[i]) {
            int len = si.size();
            for (int j = 0; j < t_len; j++) {
                dp[i + 1][j] = std::min(dp[i][j], dp[i + 1][j]);
                if (j + len > t_len) {
                    continue;
                }
                auto substr = t.substr(j, len);
                if (substr == si) {
                    dp[i + 1][j + len] = std::min(dp[i + 1][j + len], dp[i][j] + 1);
                }
            }
        }
    }

    int ans = INF;
    for (int i = 0; i <= n; i++) {
        ans = std::min(ans, dp[i][t_len]);
    }
    std::cout << (ans == INF ? -1 : ans) << std::endl;
    return 0;
}