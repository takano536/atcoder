#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int main() {
    constexpr int INF = 1e9;

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::pair<std::pair<int, int>, int>> edges(m);
    for (auto &[edge, a] : edges) {
        auto &[u, v] = edge;
        std::cin >> u >> v >> a;
        u--, v--;
    }

    std::vector<bool> exists_switch(n);
    for (int i = 0; i < k; i++) {
        int s;
        std::cin >> s;
        s--;
        exists_switch[s] = true;
    }

    std::vector graph(n * 2, std::vector<int>());

    for (int i = 0; i < n; i++) {
        if (!exists_switch[i]) continue;
        graph[i].push_back(i + n);
        graph[i + n].push_back(i);
    }

    for (const auto &[edge, is_passable] : edges) {
        auto [u, v] = edge;

        if (!is_passable) u += n, v += n;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    std::priority_queue<
        std::pair<int, int>,
        std::vector<std::pair<int, int>>,
        std::greater<std::pair<int, int>>>
    que;
    que.push({0, 0});

    std::vector<int> dists(n * 2, INF);
    dists[0] = 0;

    while (!que.empty()) {

        const auto [curr_dist, from] = que.top();
        que.pop();

        if (dists[from] < curr_dist) continue;
        dists[from] = curr_dist;

        for (const auto &to : graph[from]) {

            const bool is_moving = std::abs(from - to) < n;
            const int next_dist = curr_dist + (is_moving ? 1 : 0);

            if (dists[to] <= next_dist) continue;

            dists[to] = next_dist;
            que.push({next_dist, to});
        }
    }

    std::cout << (dists[n - 1] == INF && dists[n * 2 - 1] == INF ? -1 : std::min(dists[n - 1], dists[n * 2 - 1])) << std::endl;
    return 0;
}