#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

std::vector<int> bfs(std::vector<std::vector<int>> graph, int start) {
    std::vector<int> dists(graph.size(), -1);
    std::queue<int> que;
    que.push(start);
    dists[start] = 0;
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int nv : graph[v]) {
            if (dists[nv] != -1) {
                continue;
            }
            dists[nv] = dists[v] + 1;
            que.push(nv);
        }
    }
    return dists;
}

int main() {
    int n1, n2, m;
    std::cin >> n1 >> n2 >> m;

    std::vector<std::vector<int>> graph(n1 + n2);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    auto dists1 = bfs(graph, 0);
    auto dists2 = bfs(graph, n1 + n2 - 1);

    std::cout << *std::max_element(dists1.begin(), dists1.end()) + *std::max_element(dists2.begin(), dists2.end()) + 1 << std::endl;
}