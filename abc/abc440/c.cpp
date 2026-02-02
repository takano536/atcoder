#include <iostream>
#include <vector>

void solve() {
    constexpr long long INF = 1e18;

    int n, w;
    std::cin >> n >> w;

    std::vector<long long> grouped_c(w * 2 * 2);
    for (int i = 0; i < n; i++) {
        int c;
        std::cin >> c;
        grouped_c[i % (w * 2)] += c;
        grouped_c[i % (w * 2) + w * 2] += c;
    }

    std::vector<long long> grouped_c_cumsum(grouped_c.size() + 1);
    for (int i = 0; i < static_cast<int>(grouped_c.size()); i++) {
        grouped_c_cumsum[i + 1] = grouped_c_cumsum[i] + grouped_c[i];
    }

    long long ans = INF;
    for (int i = 0; i < static_cast<int>(grouped_c.size()) - w; i++) {
        auto total_cost = grouped_c_cumsum[i + w] - grouped_c_cumsum[i];
        ans = std::min(total_cost, ans);
    }

    std::cout << ans << '\n';
    return;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) solve();
    std::cout << std::flush;
    return 0;
}