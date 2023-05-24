#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

std::vector<int> bfs(const std::vector<std::vector<int>> &graph, int start_vertex, int goal_vertex) {
    int vertex_cnt = graph.size();
    std::vector<int> distance(vertex_cnt, -1);
    distance[start_vertex] = 0;
    std::queue<int> que;
    que.push(start_vertex);

    while (!que.empty()) {
        int curr_vertex = que.front();
        que.pop();

        for (const auto &next_vertex : graph[curr_vertex]) {
            if (distance[next_vertex] != -1) {
                continue;
            }

            que.push(next_vertex);
            distance[next_vertex] = distance[curr_vertex] + 1;
        }
    }

    // 経路復元
    std::vector<int> path = {goal_vertex};
    int curr_distance = distance[goal_vertex];
    que.push(goal_vertex);
    while (!que.empty()) {
        int curr_vertex = que.front();
        que.pop();

        for (const auto &next_vertex : graph[curr_vertex]) {
            if (distance[next_vertex] != curr_distance - 1) {
                continue;
            }

            que.push(next_vertex);
            path.push_back(next_vertex);
            curr_distance--;
        }
    }

    std::reverse(path.begin(), path.end());
    return path;
}

int main() {
    int n, x, y;
    std::cin >> n >> x >> y;
    x--, y--;

    std::vector<std::vector<int>> graph(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    auto path = bfs(graph, x, y);
    for (int vertex : path) {
        std::cout << vertex + 1 << ' ';
    }
    std::cout << std::endl;
    return 0;
}