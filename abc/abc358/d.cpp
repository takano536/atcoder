#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::multiset<int> a;
    for (int i = 0; i < n; i++) {
        int ai;
        std::cin >> ai;
        a.insert(ai);
    }

    std::vector<int> b(m);
    for (auto &bi : b) std::cin >> bi;
    std::ranges::sort(b);

    long long ans = 0;
    for (const auto &bi : b) {
        auto iter = a.lower_bound(bi);
        if (iter == a.end()) {
            ans = -1;
            break;
        }
        ans += *iter;
        a.erase(iter);
    }

    std::cout << ans << std::endl;
    return 0;
}