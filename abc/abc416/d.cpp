#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;
    std::ranges::sort(a, std::greater<int>());

    std::multiset<int> b;
    for (int i = 0; i < n; i++) {
        int bi;
        std::cin >> bi;
        b.insert(bi);
    }

    long long ans = 0;
    for (const auto &ai : a) {
        auto iter = b.lower_bound(m - ai);
        if (iter == b.end()) iter--;
        ans += (ai + *iter) % m;
        b.erase(iter);
    }

    std::cout << ans << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}