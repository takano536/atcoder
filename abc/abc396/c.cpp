#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> b(n);
    for (auto &bi : b) std::cin >> bi;

    std::vector<int> w(m);
    for (auto &wi : w) std::cin >> wi;

    std::ranges::sort(b, std::greater<int>());
    std::ranges::sort(w, std::greater<int>());

    std::vector<long long> b_cumsum(n + 1, 0);
    for (int i = 0; i < n; i++) b_cumsum[i + 1] = b_cumsum[i] + b[i];

    std::vector<long long> w_cumsum(m + 1, 0);
    for (int i = 0; i < m; i++) w_cumsum[i + 1] = w_cumsum[i] + w[i];
    int w_max_idx = 0;
    for (int i = 0; i <= m; i++) {
        if (w_cumsum[i] > w_cumsum[w_max_idx]) w_max_idx = i;
    }

    long long ans = 0;
    for (int i = 0; i <= n; i++) {
        long long total = b_cumsum[i];
        total += i >= w_max_idx ? w_cumsum[w_max_idx] : w_cumsum[i];
        ans = std::max(ans, total);
    }

    std::cout << ans << std::endl;
    return 0;
}