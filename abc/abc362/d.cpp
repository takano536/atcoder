#include <iostream>
#include <queue>
#include <vector>

int main() {
    constexpr long long INF = 8e18;

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    std::vector graph(n, std::vector<std::pair<long long, int>>());
    for (int i = 0; i < m; i++) {
        int u, v;
        long long b;
        std::cin >> u >> v >> b;
        u--, v--;
        graph[u].emplace_back(b + a[v], v);
        graph[v].emplace_back(b + a[u], u);
    }

    std::vector<bool> has_visited(n);
    std::vector<long long> dists(n, INF);
    std::priority_queue<
        std::pair<long long, int>,
        std::vector<std::pair<long long, int>>,
        std::greater<std::pair<long long, int>>
    > que;
    que.emplace(a[0], 0);

    while (!que.empty()) {
        auto [cost, from] = que.top();
        que.pop();

        if (has_visited[from]) continue;
        has_visited[from] = true;
        dists[from] = cost;

        for (const auto &[next_cost, to] : graph[from]) {
            if (has_visited[to]) continue;
            if (dists[to] > cost + next_cost) {
                dists[to] = cost + next_cost;
                que.emplace(dists[to], to);
            }
        }
    }

    for (int i = 1; i < n; i++) std::cout << dists[i] << ' ';
    std::cout << std::endl;
    return 0;
}