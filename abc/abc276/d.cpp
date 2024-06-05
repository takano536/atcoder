#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    std::vector<int> doub_cnts(n), tri_cnts(n);
    for (int i = 0; auto &ai : a) {
        while (ai % 2 == 0) ai /= 2, doub_cnts[i]++;
        while (ai % 3 == 0) ai /= 3, tri_cnts[i]++;
        i++;
    }

    if (!std::ranges::all_of(a, [&](const int ai) { return ai == a.front(); })) {
        std::cout << -1 << std::endl;
        return 0;
    }

    int doub_min = *std::ranges::min_element(doub_cnts);
    int tri_min = *std::ranges::min_element(tri_cnts);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += doub_cnts[i] - doub_min;
        ans += tri_cnts[i] - tri_min;
    }

    std::cout << ans << std::endl;
    return 0;
}