#include <iostream>
#include <set>
#include <utility>
#include <vector>

int main() {
    constexpr long long INF = 8e18;

    int n, m;
    std::cin >> n >> m;

    std::vector graph(n, std::vector<std::pair<long long, int>>());
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        std::cin >> u >> v >> w;
        u--, v--;
        graph[u].emplace_back(w, v);
        graph[v].emplace_back(w, u);
    }

    long long ans = INF;
    auto dfs = [&](auto &&f, int curr, long long value, std::set<int> &has_visited) -> void {
        if (curr == n - 1) {
            ans = std::min(ans, value);
            return;
        }

        has_visited.insert(curr);
        for (const auto &[next_value, next] : graph[curr]) {
            if (has_visited.contains(next)) continue;
            f(f, next, value ^ next_value, has_visited);
        }
        has_visited.erase(curr);
        return;
    };

    std::set<int> has_visited;
    dfs(dfs, 0, 0, has_visited);
    std::cout << ans << std::endl;
    return 0;
}