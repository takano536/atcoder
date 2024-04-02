#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &ai : a) {
        std::cin >> ai;
        ai--;
    }

    std::vector idxes(n, std::vector<int>());
    for (int i = 0; i < n; i++) {
        idxes[a[i]].push_back(i);
    }

    int q;
    std::cin >> q;
    for (int query = 0; query < q; query++) {
        int l, r, x;
        std::cin >> l >> r >> x;
        l--, r--, x--;

        auto l_iter = std::ranges::lower_bound(idxes[x], l);
        auto r_iter = std::ranges::upper_bound(idxes[x], r);

        int ans = std::distance(idxes[x].begin(), r_iter) - std::distance(idxes[x].begin(), l_iter);
        std::cout << ans << std::endl;
    }
    return 0;
}