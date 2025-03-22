#include <iostream>
#include <set>
#include <utility>
#include <vector>

int main() {
    constexpr int NA = -1;

    int n;
    std::cin >> n;

    std::set<std::pair<int, int>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) edges.insert({i, j});
    }

    std::vector<std::vector<int>> graph(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);

        if (u > v) std::swap(u, v);
        edges.erase({u, v});
    }

    std::vector<int> colors(n, NA);
    auto dfs = [&](auto &&f, int v, int p, int c) -> void {
        colors[v] = c;
        for (const auto &u : graph[v]) {
            if (u == p) continue;
            f(f, u, v, c ^ 1);
        }
    };
    dfs(dfs, 0, -1, 0);

    auto ans = edges;
    for (const auto &[u, v] : edges) {
        if (colors[u] == colors[v]) ans.erase({u, v});
    }

    bool turn = ans.size() % 2;
    std::cout << (turn == true ? "First" : "Second") << std::endl;
    int i = 0, j = 0;
    while (true) {
        if (turn == true) {
            auto [u, v] = *ans.begin();
            ans.erase(ans.begin());
            std::cout << u + 1 << " " << v + 1 << std::endl;

        } else {
            std::cin >> i >> j;
            if (i == NA && j == NA) break;
            i--, j--;
            if (i > j) std::swap(i, j);
            ans.erase({i, j});
        }
        turn = !turn;
    }

    return 0;
}