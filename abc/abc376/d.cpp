#include <iostream>
#include <queue>
#include <vector>

int main() {
    constexpr int INF = 1e9;

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        if (b == 0) b = n;
        graph[a].push_back(b);
    }

    std::vector<int> dist(n + 1, INF);
    std::queue<int> que;

    dist[0] = 0;
    que.push(0);

    while (!que.empty()) {
        auto pv = que.front();
        que.pop();

        for (const auto &nv : graph[pv]) {
            if (dist[nv] != INF) continue;
            dist[nv] = dist[pv] + 1;
            que.push(nv);
        }
    }

    std::cout << (dist[n] == INF ? -1 : dist[n]) << std::endl;
    return 0;
}