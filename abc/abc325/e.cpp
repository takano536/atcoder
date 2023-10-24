#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int main() {
    const long INF = 1e18;

    int n, a, b, c;
    std::cin >> n >> a >> b >> c;

    std::vector<std::vector<int>> d(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> d[i][j];
        }
    }

    auto dijkstra = [&](const std::vector<std::vector<long>> &graph, int sv) -> std::vector<long> {
        std::vector<long> dists(n, INF);
        std::priority_queue<std::pair<long, int>, std::vector<std::pair<long, int>>, std::greater<std::pair<long, int>>> que;

        que.push({0, sv});
        while (!que.empty()) {
            auto [curr_d, curr_v] = que.top();
            que.pop();

            if (dists[curr_v] != INF) {
                continue;
            }

            dists[curr_v] = curr_d;

            for (int next_v = 0; next_v < n; next_v++) {
                if (next_v == curr_v) {
                    continue;
                }
                if (dists[next_v] != INF) {
                    continue;
                }
                que.push({curr_d + graph[curr_v][next_v], next_v});
            }
        }

        return dists;
    };

    std::vector<std::vector<long>> car_graph(n, std::vector<long>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            car_graph[i][j] = static_cast<long>(d[i][j]) * a;
        }
    }
    auto car_dists = dijkstra(car_graph, 0);

    std::vector<std::vector<long>> train_graph(n, std::vector<long>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            train_graph[i][j] = static_cast<long>(d[i][j]) * b + c;
        }
    }
    auto train_dists = dijkstra(train_graph, n - 1);

    long ans = 1e18;
    for (int i = 0; i < n; i++) {
        ans = std::min(ans, car_dists[i] + train_dists[i]);
    }

    std::cout << ans << std::endl;
    return 0;
}