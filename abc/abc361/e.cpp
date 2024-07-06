#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int main() {
    constexpr long long INF = 8e18;

    int n;
    std::cin >> n;

    std::vector graph(n, std::vector<std::pair<int, int>>());
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--, b--;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
        ans += c;
    }

    auto bfs = [&](int sv, int gv = -1) -> std::pair<int, long long> {
        std::queue<std::pair<int, long long>> que;
        que.push({sv, 0});
        std::vector<long long> costs(n, INF);
        costs[sv] = 0;

        while (!que.empty()) {
            auto [from, accum_cost] = que.front();
            que.pop();

            for (const auto &[to, cost] : graph[from]) {
                if (costs[to] != INF) continue;
                costs[to] = accum_cost + cost;
                que.push({to, accum_cost + cost});
            }
        }

        if (gv == -1) {
            auto max_iter = std::ranges::max_element(costs);
            return {std::ranges::distance(costs.begin(), max_iter), *max_iter};
        } else {
            return {gv, costs[gv]};
        }
    };

    auto [u, _] = bfs(0);
    auto [v, __] = bfs(u);
    auto [___, diameter] = bfs(u, v);

    std::cout << ans * 2 - diameter << std::endl;
    return 0;
}