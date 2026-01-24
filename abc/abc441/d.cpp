#include <iostream>
#include <set>
#include <utility>
#include <vector>

int main() {
    int n, m, l, s, t;
    std::cin >> n >> m >> l >> s >> t;

    std::vector<std::vector<std::pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        std::cin >> u >> v >> c;
        u--, v--;
        graph[u].emplace_back(v, c);
    }

    std::set<int> ans;
    auto dfs = [&](auto &&self, const int curr, const int count = 0, const long long cost = 0) {
        if (count == l) {
            if (s <= cost && cost <= t) ans.insert(curr + 1);
            return;
        }
        for (const auto &[v, c] : graph[curr]) self(self, v, count + 1, cost + c);
        return;
    };

    dfs(dfs, 0);

    for (const auto &v : ans) std::cout << v << ' ';
    std::cout << std::endl;
    return 0;
}