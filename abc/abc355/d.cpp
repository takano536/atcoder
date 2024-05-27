#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) std::cin >> l[i] >> r[i];

    std::ranges::sort(r);

    long long ans = static_cast<long long>(n) * (n - 1) / 2;
    for (const auto &li : l) {
        auto iter = std::ranges::lower_bound(r, li);
        auto dist = std::distance(r.begin(), iter);
        ans -= dist;
    }

    std::cout << ans << std::endl;
    return 0;
}