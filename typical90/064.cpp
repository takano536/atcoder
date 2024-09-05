#include <iostream>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    std::vector<long long> diffs(n);
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        diffs[i] = a[i] - a[i - 1];
        ans += std::abs(diffs[i]);
    }

    while (q--) {
        int l, r, v;
        std::cin >> l >> r >> v;
        auto prev = std::abs(diffs[l - 1]) + std::abs(diffs[r]);
        if (l > 1) diffs[l - 1] += v;
        if (r < n) diffs[r] -= v;
        auto curr = std::abs(diffs[l - 1]) + std::abs(diffs[r]);
        ans += curr - prev;
        std::cout << ans << std::endl;
    }
    return 0;
}