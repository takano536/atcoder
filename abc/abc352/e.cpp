#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#include <atcoder/dsu>

int main() {
    int n, m;
    std::cin >> n >> m;

    atcoder::dsu tree(n);
    std::vector<int> k(m);
    std::vector<std::pair<int, int>> c(m);
    std::vector a(m, std::vector<int>());
    for (int i = 0; i < m; i++) {
        std::cin >> k[i] >> c[i].first;
        c[i].second = i;
        for (int j = 0; j < k[i]; j++) {
            int aj;
            std::cin >> aj;
            a[i].push_back(aj - 1);
        }
        for (int j = 0; j < k[i] - 1; j++) {
            tree.merge(a[i][j], a[i][j + 1]);
        }
    }

    if (tree.groups().size() > 1) {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::ranges::sort(c);
    long long ans = 0;
    atcoder::dsu min_spanning_tree(n);
    for (const auto &[cost, i] : c) {
        int k = a[i].size();
        for (int j = 0; j < k - 1; j++) {
            if (min_spanning_tree.same(a[i][j], a[i][j + 1])) continue;
            min_spanning_tree.merge(a[i][j], a[i][j + 1]);
            ans += cost;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}