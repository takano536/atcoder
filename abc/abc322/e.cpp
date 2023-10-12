#include <iostream>
#include <map>
#include <vector>

int main() {
    int n, k, p;
    std::cin >> n >> k >> p;

    std::vector<int> c(n);
    std::vector<std::vector<int>> a(n, std::vector<int>(k));
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
        for (int j = 0; j < k; j++) {
            std::cin >> a[i][j];
        }
    }

    std::vector<std::map<std::vector<int>, long long>> dp(n + 1);
    dp[0][std::vector<int>(k, 0)] = 0;

    for (int i = 1; i <= n; i++) {
        for (auto prev : dp[i - 1]) {
            dp[i][prev.first] = prev.second;
        }
        auto plan_idx = i - 1;
        for (auto prev : dp[i - 1]) {
            auto next_params = prev.first;
            for (int i = 0; i < k; i++) {
                next_params[i] = std::min(p, prev.first[i] + a[plan_idx][i]);
            }
            if (dp[i].contains(next_params)) {
                dp[i][next_params] = std::min(dp[i][next_params], prev.second + c[plan_idx]);
            } else {
                dp[i][next_params] = prev.second + c[plan_idx];
            }
        }
    }

    long long INF = 1e18;
    long long ans = INF;
    for (const auto &[params, cost] : dp[n]) {
        bool satisfied = true;
        for (auto param : params) {
            if (param < p) {
                satisfied = false;
                break;
            }
        }
        if (satisfied) {
            ans = std::min(ans, cost);
        }
    }

    std::cout << (ans == INF ? -1 : ans) << std::endl;
}