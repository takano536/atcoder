#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

std::vector<int> bfs(const std::vector<std::vector<int>> &graph, int start_vertex) {
    int vertex_cnt = graph.size();
    std::vector<int> dist(vertex_cnt, -1);
    dist[start_vertex] = 0;
    std::queue<int> que;
    que.push(start_vertex);

    while (!que.empty()) {
        int curr_vertex = que.front();
        que.pop();

        for (const auto &vertex : graph[curr_vertex]) {
            if (dist[vertex] != -1) {
                continue;
            }

            que.push(vertex);
            dist[vertex] = dist[curr_vertex] + 1;
        }
    }

    return dist;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int k;
    std::cin >> k;
    std::map<int, int> min_dists;
    for (int i = 0; i < k; i++) {
        int p, d;
        std::cin >> p >> d;
        min_dists[p - 1] = d;
    }

    std::vector<std::vector<int>> dists(n);
    for (int i = 0; i < n; i++) {
        dists[i] = bfs(graph, i);
    }

    std::vector<bool> is_white(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (min_dists.find(i) == min_dists.end()) {
                continue;
            }

            if (dists[i][j] < min_dists[i]) {
                is_white[j] = true;
            }
        }
    }

    bool satisfies = std::any_of(is_white.begin(), is_white.end(), [](bool is_true) { return !is_true; });
    for (const auto &[vertex, dist] : min_dists) {
        int min_dist = 1e9;
        for (int i = 0; i < n; i++) {
            if (!is_white[i]) {
                min_dist = std::min(dists[vertex][i], min_dist);
            }
        }
        if (min_dist != dist) {
            satisfies = false;
        }
    }
    std::cout << (satisfies ? "Yes" : "No") << std::endl;
    if (satisfies) {
        for (bool is_true : is_white) {
            std::cout << (is_true ? '0' : '1');
        }
        std::cout << std::endl;
    }

    return 0;
}