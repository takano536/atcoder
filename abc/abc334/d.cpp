#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> r(n);
    for (auto &ri : r) {
        std::cin >> ri;
    }

    std::ranges::sort(r);
    std::vector<long long> cumsum(n + 1);
    for (int i = 0; i < n; i++) {
        cumsum[i + 1] = cumsum[i] + r[i];
    }

    for (int i = 0; i < q; i++) {
        long long query;
        std::cin >> query;
        auto iter = std::ranges::lower_bound(cumsum, query);
        auto ans = std::distance(cumsum.begin(), iter) - 1;
        if (std::ranges::binary_search(cumsum, query)) {
            ans++;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}