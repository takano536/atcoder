#include <iostream>
#include <string>
#include <vector>

int main() {
    int h, w, n;
    std::cin >> h >> w >> n;

    std::vector<std::vector<bool>> is_hole(h, std::vector<bool>(w));
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        is_hole[a][b] = true;
    }

    long long ans = 0;
    std::vector<std::vector<int>> dp(h, std::vector<int>(w, -1));
    for (int i = 0; i < h; i++) {
        dp[i][0] = is_hole[i][0] ? -1 : 1;
        ans += !is_hole[i][0];
    }
    for (int i = 1; i < w; i++) {
        dp[0][i] = is_hole[0][i] ? -1 : 1;
        ans += !is_hole[0][i];
    }

    for (int i = 1; i < h; i++) {
        for (int j = 1; j < w; j++) {
            if (is_hole[i][j]) {
                continue;
            }
            dp[i][j] = 1;
            if (dp[i - 1][j] != -1 && dp[i][j - 1] != -1 && dp[i - 1][j - 1] != -1) {
                dp[i][j] = std::min(dp[i - 1][j], std::min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                ans += dp[i][j];
            } else {
                ans++;
            }
        }
    }

    std::cout << ans << std::endl;
}