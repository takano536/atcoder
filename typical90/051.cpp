#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, k;
    long long p;
    std::cin >> n >> k >> p;

    std::vector<long long> a(n);
    for (auto &ai : a) std::cin >> ai;

    auto calc = [](const std::vector<long long> prices) {
        std::vector<std::vector<long long>> ret(prices.size() + 1);

        for (int bit = 0; bit < (1 << prices.size()); bit++) {
            long long total = 0;
            int cnt = 0;
            for (std::size_t i = 0; i < prices.size(); i++) {
                if (!(bit & (1 << i))) continue;
                total += prices[i];
                cnt++;
            }
            ret[cnt].push_back(total);
        }
        for (auto &v : ret) std::ranges::sort(v);

        return ret;
    };

    const auto g1 = calc(std::vector(a.begin(), std::next(a.begin(), n / 2)));
    const auto g2 = calc(std::vector(std::next(a.begin(), n / 2), a.end()));

    long long ans = 0;
    for (int i = 0; i < std::min<int>(k, g1.size()); i++) {
        if (static_cast<int>(g2.size()) <= k - i) continue;
        if (g2[k - i].size() == 0) continue;

        for (const auto &amount : g1[i]) {
            if (amount > p) continue;

            const auto iter = std::ranges::upper_bound(g2[k - i], p - amount);
            ans += std::distance(g2[k - i].begin(), iter);
        }
    }

    if (g1.size() >= static_cast<std::size_t>(k + 1)) {
        for (const auto &amount : g1[k]) ans += (amount <= p ? 1 : 0);
    }

    std::cout << ans << std::endl;
    return 0;
}