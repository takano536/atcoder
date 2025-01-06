#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    constexpr int NA = -1;

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> graph(n);
    std::vector<int> indegrees(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        indegrees[u]++;
        indegrees[v]++;
    }

    std::vector<int> ans;
    std::vector<bool> has_visited(n);
    std::vector<int> colors(n, NA);
    auto dfs = [&](auto &&f, int prev) -> void {
        has_visited[prev] = true;
        for (const auto &next : graph[prev]) {
            if (colors[next] == NA) colors[next] = (colors[prev] + 1) % 3;
            if (indegrees[next] == 1) continue;
            if (has_visited[next]) continue;
            f(f, next);
        }
        if (colors[prev] % 3 == 1) ans.push_back(indegrees[prev]);
        return;
    };

    int sv = 0;
    for (int i = 0; i < n; i++) {
        if (indegrees[i] != 1) continue;
        sv = i;
        break;
    }

    colors[sv] = 0;
    dfs(dfs, sv);

    std::ranges::sort(ans);
    for (auto &num : ans) std::cout << num << ' ';
    std::cout << std::endl;
}