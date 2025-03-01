#include <iostream>
#include <queue>
#include <vector>

int main() {
    constexpr long long INF = 8e18;

    int n, m, x;
    std::cin >> n >> m >> x;

    std::vector graph(n * 2, std::vector<std::pair<int, int>>());
    for (int i = 0; i < n; i++) {
        graph[i].emplace_back(x, i + n);
        graph[i + n].emplace_back(x, i);
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        graph[a].emplace_back(1, b);
        graph[b + n].emplace_back(1, a + n);
    }

    std::vector<bool> has_visited(n * 2);
    std::vector<long long> dists(n * 2, INF);
    using P = std::pair<long long, int>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> que;
    que.emplace(0, 0);

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

    std::cout << std::min(dists[n - 1], dists[n * 2 - 1]) << std::endl;
    return 0;
}