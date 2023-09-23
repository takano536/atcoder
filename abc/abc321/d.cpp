#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

int main() {
    int n, m, p;
    std::cin >> n >> m >> p;
    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }

    std::ranges::sort(a);
    std::ranges::sort(b);

    std::vector<long long> b_cumsum(m + 1);
    b_cumsum[0] = 0;
    for (int i = 0; i < m; i++) {
        b_cumsum[i + 1] = b_cumsum[i] + b[i];
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int b_max = p - a[i];
        auto it = std::ranges::upper_bound(b, b_max);
        int b_idx = std::distance(b.begin(), it);
        ans += static_cast<long long>(m - b_idx) * p;
        ans += b_cumsum[b_idx] + a[i] * static_cast<long long>(b_idx);
    }

    std::cout << ans << std::endl;
    return 0;
}