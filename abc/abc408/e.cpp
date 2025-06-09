#include <iostream>
#include <set>
#include <tuple>
#include <utility>
#include <vector>

#include <atcoder/dsu>

int main() {
    constexpr int BIT_COUNT = 30;

    int n, m;
    std::cin >> n >> m;

    int ans = 0;
    std::vector<std::tuple<int, int, int, int>> edges(m);
    for (int index = 0; auto &[u, v, w, i] : edges) {
        std::cin >> u >> v >> w;
        u--, v--;
        ans |= w;
        i = index++;
    }

    std::set<int> available_edges;
    for (int i = 0; i < m; i++) available_edges.insert(i);

    for (int bit = BIT_COUNT - 1; bit >= 0; bit--) {
        if ((ans & (1 << bit)) == 0) continue;

        atcoder::dsu union_find(n);
        std::vector<int> unused_edges;
        for (const auto &[u, v, w, i] : edges) {
            if (!available_edges.contains(i)) continue;
            if (w & (1 << bit)) {
                unused_edges.push_back(i);
                continue;
            }
            union_find.merge(u, v);
        }
        if (!union_find.same(0, n - 1)) continue;

        ans ^= (1 << bit);
        for (const auto &i : unused_edges) available_edges.erase(i);
    }

    std::cout << ans << std::endl;
    return 0;
}