#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int main() {
    constexpr long long INF = 8e18;

    int n, m;
    std::cin >> n >> m;

    std::vector<int> h(n);
    for (auto &hi : h) std::cin >> hi;

    std::vector graph(n, std::vector<std::pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        graph[u].emplace_back(v, std::max(h[v] - h[u], 0));
        graph[v].emplace_back(u, std::max(h[u] - h[v], 0));
    }

    std::priority_queue<
        std::pair<long long, int>,
        std::vector<std::pair<long long, int>>,
        std::greater<std::pair<long long, int>>
    > que;
    que.emplace(0, 0);

    std::vector<long long> costs(n, INF);
    std::vector<bool> has_visited(n);

    while (!que.empty()) {
        const auto [accum_cost, from] = que.top();
        que.pop();

        if (has_visited[from]) continue;
        has_visited[from] = true;
        costs[from] = accum_cost;

        for (const auto &[to, cost] : graph[from]) {

            if (costs[to] <= accum_cost + cost) continue;

            costs[to] = accum_cost + cost;
            que.emplace(accum_cost + cost, to);
        }
    }

    long long ans = -INF;
    for (int i = 0; i < n; i++) ans = std::max(-costs[i] + h[0] - h[i], ans);

    std::cout << ans << std::endl;
    return 0;
}