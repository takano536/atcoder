#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> x(n), p(n);
    for (auto &xi : x) std::cin >> xi;
    for (auto &pi : p) std::cin >> pi;

    std::vector<long long> cumsum(n + 1);
    for (int i = 0; i < n; i++) cumsum[i + 1] = cumsum[i] + p[i];

    int q;
    std::cin >> q;

    while (q--) {
        int l, r;
        std::cin >> l >> r;
        auto l_iter = std::lower_bound(x.begin(), x.end(), l);
        auto r_iter = std::prev(std::upper_bound(x.begin(), x.end(), r));

        auto l_idx = std::distance(x.begin(), l_iter);
        auto r_idx = std::distance(x.begin(), r_iter);
        std::cout << cumsum[r_idx + 1] - cumsum[l_idx] << std::endl;
    }
    return 0;
}