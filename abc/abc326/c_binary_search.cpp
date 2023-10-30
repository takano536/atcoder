#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (auto &in : a) {
        std::cin >> in;
    }

    std::ranges::sort(a);

    int ans = 1;
    for (int i = 0; i < n; i++) {
        auto iter = std::ranges::upper_bound(a, static_cast<long>(a[i]) + m - 1);
        iter--;
        if (iter == a.end()) {
            continue;
        }
        int idx = std::distance(a.begin(), iter);
        ans = std::max(ans, idx - i + 1);
    }

    std::cout << ans << std::endl;
    return 0;
}