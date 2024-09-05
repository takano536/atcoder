#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, s;
    std::cin >> n >> s;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) std::cin >> a[i] >> b[i];

    std::vector dp(n, std::vector<bool>(s + 1));
    dp[0][a[0]] = true;
    dp[0][b[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= s; j++) {
            if (dp[i - 1][j] == false) continue;
            if (j + a[i] <= s) dp[i][j + a[i]] = true;
            if (j + b[i] <= s) dp[i][j + b[i]] = true;
        }
    }

    if (dp[n - 1][s] == false) {
        std::cout << "Impossible" << std::endl;
        return 0;
    }

    int curr = s;
    std::string ans;
    for (int i = n - 1; i >= 0; i--) {
        if (i == 0 && curr - a[i] == 0) {
            ans += "A";
            break;
        }
        if (i == 0 && curr - b[i] == 0) {
            ans += "B";
            break;
        }
        if (curr - a[i] >= 0 && dp[i - 1][curr - a[i]] == true) {
            ans += "A";
            curr -= a[i];
        } else {
            ans += "B";
            curr -= b[i];
        }
    }
    std::ranges::reverse(ans);

    std::cout << ans << std::endl;
    return 0;
}