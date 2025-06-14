#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int main() {
    constexpr int INF = 1 << 10;

    int n, m;
    std::cin >> n >> m;

    std::vector graph(n, std::vector<std::pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        graph[u].emplace_back(v, w);
    }

    std::queue<std::pair<int, int>> que;
    que.emplace(0, 0);

    std::vector has_visited(n + 1, std::vector<bool>(INF));
    has_visited[0][0] = true;

    int ans = INF;
    while (!que.empty()) {
        const auto [curr_v, curr_w] = que.front();
        que.pop();

        if (curr_v == n - 1) ans = std::min(curr_w, ans);

        for (const auto &[next_v, w] : graph[curr_v]) {
            const auto next_w = curr_w ^ w;
            if (has_visited[next_v][next_w]) continue;
            has_visited[next_v][next_w] = true;
            que.emplace(next_v, next_w);
        }
    }

    std::cout << (ans != INF ? ans : -1) << std::endl;
    return 0;
}
