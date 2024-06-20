#include <iostream>
#include <vector>

int main() {
    constexpr int MAX_ANS = 1e6;

    int n, m;
    std::cin >> n >> m;

    std::vector graph(n, std::vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int ans = 0;
    auto dfs = [&](auto f, int from, std::vector<bool> &has_visited) -> void {
        has_visited[from] = true;
        if (ans >= MAX_ANS) return;
        ans++;

        for (const auto &to : graph[from]) {
            if (has_visited[to]) continue;
            f(f, to, has_visited);
            if (ans >= MAX_ANS) return;
            has_visited[to] = false;
        }
        return;
    };

    std::vector<bool> has_visited(n);
    dfs(dfs, 0, has_visited);

    std::cout << ans << std::endl;
    return 0;
}