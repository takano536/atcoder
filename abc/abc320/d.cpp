#include <algorithm>
#include <iostream>
#include <vector>

namespace mymodules {

struct Edge {
    int to;
    long long x, y;
    Edge(int to, long long x, long long y)
        : to(to), x(x), y(y) {
    }
};

}  // namespace mymodules

int main() {
    const long long INF = 1e18;

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<mymodules::Edge>> graph(n);
    std::vector<int> a(m), b(m), x(m), y(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> a[i] >> b[i] >> x[i] >> y[i];
        a[i]--, b[i]--;
        graph[a[i]].emplace_back(b[i], x[i], y[i]);
        graph[b[i]].emplace_back(a[i], -x[i], -y[i]);
    }

    std::vector<std::pair<long long, long long>> dists(n, {INF, INF});
    dists[0] = {0, 0};

    auto dfs = [&](auto &&dfs, int v, long long x, long long y) -> void {
        for (const auto &edge : graph[v]) {
            if (dists[edge.to] != std::pair<long long, long long>{INF, INF}) {
                continue;
            }
            dists[edge.to] = {x + edge.x, y + edge.y};
            dfs(dfs, edge.to, x + edge.x, y + edge.y);
        }
    };

    dfs(dfs, 0, 0, 0);

    for (const auto &dist : dists) {
        if (dist != std::pair<long long, long long>{INF, INF}) {
            std::cout << dist.first << " " << dist.second << std::endl;
        } else {
            std::cout << "undecidable" << std::endl;
        }
    }
    return 0;
}