#include <iostream>
#include <set>
#include <string>
#include <vector>

void solve() {
    int n, m, x, y;
    std::cin >> n >> m >> x >> y;
    x--, y--;

    std::vector<std::set<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        graph[u].insert(v), graph[v].insert(u);
    }

    std::vector<bool> has_visited(n);
    auto dfs = [&](auto &&self, std::vector<int> &path) -> void {
        if (path.back() == y) {
            for (const auto &u : path) std::cout << u + 1 << ' ';
            std::cout << std::endl;
            return;
        }
        for (const auto &next : graph[path.back()]) {
            if (has_visited[next]) continue;
            has_visited[next] = true;
            path.push_back(next);
            self(self, path);
            path.pop_back();
        }
    };

    std::vector<int> ans = {x};
    has_visited[x] = true;
    dfs(dfs, ans);
}

int main() {
    int t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}