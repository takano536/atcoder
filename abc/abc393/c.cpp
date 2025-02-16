#include <iostream>
#include <set>
#include <utility>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::set<std::pair<int, int>> edges;
    int bridge_num = 0;
    for (int _ = 0; _ < m; _++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        if (u > v) std::swap(u, v);
        if (u == v) continue;
        if (edges.contains({u, v})) continue;
        bridge_num++;
        edges.insert({u, v});
    }

    std::cout << m - bridge_num << std::endl;
    return 0;
}