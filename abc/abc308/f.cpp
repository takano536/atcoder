#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> p(n);
    for (auto &P : p) {
        std::cin >> P;
    }

    std::vector<int> l(m), d(m);
    for (auto &L : l) {
        std::cin >> L;
    }
    for (auto &D : d) {
        std::cin >> D;
    }

    std::vector<std::pair<int, int>> vouchers(m);
    for (int i = 0; i < m; i++) {
        vouchers[i] = {d[i], l[i]};
    }
    std::sort(vouchers.begin(), vouchers.end());

    long long ans = 0;
    std::multiset<int> regular_prices(p.begin(), p.end());
    for (int i = 0; i < m; i++) {
        auto voucher = vouchers.back();
        vouchers.pop_back();

        auto price_iter = regular_prices.lower_bound(voucher.second);
        if (price_iter == regular_prices.end()) {
            continue;
        }
        regular_prices.erase(price_iter);
        ans += *price_iter - voucher.first;
    }

    ans = std::accumulate(regular_prices.begin(), regular_prices.end(), ans);
    std::cout << ans << std::endl;
    return 0;
}