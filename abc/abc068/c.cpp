#include <iostream>
#include <queue>
#include <vector>

int main() {
    constexpr int INF = 1e9;

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        graph[a].push_back(b), graph[b].push_back(a);
    }

    std::vector<int> dists(n, INF);
    std::queue<int> que;
    dists[0] = 0;
    que.push(0);
    while (!que.empty()) {
        const auto curr = que.front();
        que.pop();

        for (const auto next : graph[curr]) {
            if (dists[next] != INF) continue;
            dists[next] = dists[curr] + 1;
            que.push(next);
        }
    }

    std::cout << (dists[n - 1] > 2 ? "IMPOSSIBLE" : "POSSIBLE") << std::endl;
    return 0;
}