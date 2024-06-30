#include <iostream>
#include <map>
#include <set>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    std::map<int, std::set<int>> w;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int wi;
        std::cin >> wi;
        w[a[i]].insert(wi);
        ans += wi;
    }

    for (const auto &[i, wi] : w) ans -= *wi.rbegin();

    std::cout << ans << std::endl;
    return 0;
}