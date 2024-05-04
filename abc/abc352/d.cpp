#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::pair<int, int>> p(n);
    for (int i = 0; auto &[pi, idx] : p) {
        std::cin >> pi;
        idx = i++;
    }

    std::ranges::sort(p);

    int ans = 1e9;
    std::set<int> asc;
    for (int i = 0; i < k; i++) {
        asc.insert(p[i].second);
    }
    ans = std::min(ans, *asc.rbegin() - *asc.begin());

    for (int i = k; i < n; i++) {
        asc.erase(p[i - k].second);
        asc.insert(p[i].second);
        ans = std::min(ans, *asc.rbegin() - *asc.begin());
    }

    std::cout << ans << std::endl;
    return 0;
}