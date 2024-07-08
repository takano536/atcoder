#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

struct Edge {
    int to;
    long long cost;
    int idx;
    Edge() : to(0), cost(0), idx(0) {}
    Edge(int to, long long cost, int idx) : to(to), cost(cost), idx(idx) {}
    bool operator<(const Edge &lhs) const { return cost < lhs.cost; }
    bool operator>(const Edge &lhs) const { return cost > lhs.cost; }
};

int main() {
    constexpr long long INF = 8e18;
    constexpr int NA = -1;

    int n, m;
    std::cin >> n >> m;

    std::vector graph(n, std::vector<Edge>());
    for (int i = 0; i < m; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--, b--;
        graph[a].push_back(Edge(b, c, i));
        graph[b].push_back(Edge(a, c, i));
    }

    std::vector<int> ans;
    std::vector<long long> costs(n, INF);
    std::vector<bool> has_visited(n);
    std::priority_queue<
        Edge,
        std::vector<Edge>,
        std::greater<Edge>
    > que;
    que.emplace(0, 0, NA);

    while (!que.empty()) {

        auto [from, accum_cost, from_i] = que.top();
        que.pop();

        if (has_visited[from]) continue;
        has_visited[from] = true;
        costs[from] = accum_cost;
        if (from_i != NA) ans.push_back(from_i + 1);

        for (const auto& [to, cost, to_i] : graph[from]) {

            if (costs[to] <= accum_cost + cost) continue;
            costs[to] = accum_cost + cost;
            que.emplace(to, accum_cost + cost, to_i);
        }
    }

    for (const auto& i : ans) std::cout << i << ' ';
    std::cout << std::endl;
    return 0;
}