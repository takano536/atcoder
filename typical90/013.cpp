#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int main() {
    const int INF = 1e9;

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--, b--;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    auto bfs = [&](int sv) -> std::vector<int> {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> que;
        que.push({0, sv});
        std::vector<int> dists(n, INF);
        dists[sv] = 0;

        while (!que.empty()) {
            auto [curr_cost, curr_idx] = que.top();
            que.pop();

            for (const auto &[next_idx, next_cost] : graph[curr_idx]) {
                int cost = curr_cost + next_cost;
                if (cost >= dists[next_idx]) {
                    continue;
                }
                dists[next_idx] = cost;
                que.push({cost, next_idx});
            }
        }
        return dists;
    };

    auto dists_from_start = bfs(0);
    auto dists_from_goal = bfs(n - 1);

    for (int i = 0; i < n; i++) {
        std::cout << dists_from_start[i] + dists_from_goal[i] << std::endl;
    }
    return 0;
}