#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> graph(n);
    std::vector<int> indegrees(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;

        graph[y].push_back(x);
        indegrees[x]++;
    }

    std::queue<int> que;
    for (int vertex = 0; vertex < n; vertex++) {
        if (indegrees[vertex] == 0) {
            que.push(vertex);
        }
    }

    std::vector<int> a(n);
    int curr_num = n;
    bool satisfies = true;
    while (!que.empty()) {
        if (que.size() > 1) {
            satisfies = false;
            break;
        }

        auto curr_vertex = que.front();
        que.pop();
        a[curr_vertex] = curr_num;
        curr_num--;

        for (auto next_vertex : graph[curr_vertex]) {
            indegrees[next_vertex]--;
            if (indegrees[next_vertex] == 0) {
                que.push(next_vertex);
            }
        }
    }

    if (!satisfies) {
        std::cout << "No" << std::endl;
        return 0;
    }

    std::cout << "Yes" << std::endl;
    for (const auto &num : a) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    return 0;
}