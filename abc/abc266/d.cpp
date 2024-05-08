#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    const int MAX_HOLE = 5;
    const int MAX_TIME = 1e5;
    const int NA = -1;

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> sunkes(MAX_TIME + 1, {NA, 0});
    int max_time = 0;
    for (int i = 0; i < n; i++) {
        int t, x, a;
        std::cin >> t >> x >> a;
        sunkes[t] = {x, a};
        max_time = std::max(max_time, t);
    }

    std::vector dp(max_time + 1, std::vector<long long>(5, NA));
    dp[0][0] = 0;
    for (int time = 1; time <= max_time; time++) {

        const auto [hole, size] = sunkes[time];
        for (int i = 0; i < MAX_HOLE; i++) {
            if (dp[time - 1][i] == NA) continue;
            dp[time][i] = std::max(dp[time - 1][i] + (i == hole ? size : 0), dp[time][i]);
            if (i - 1 >= 0) {
                dp[time][i - 1] = std::max(dp[time - 1][i] + (i - 1 == hole ? size : 0), dp[time][i - 1]);
            }
            if (i + 1 < MAX_HOLE) {
                dp[time][i + 1] = std::max(dp[time - 1][i] + (i + 1 == hole ? size : 0), dp[time][i + 1]);
            }
        }
    }

    std::cout << *std::ranges::max_element(dp[max_time]) << std::endl;
    return 0;
}