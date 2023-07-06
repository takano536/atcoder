#include <iostream>
#include <queue>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> g(n);
    std::vector<int> indegrees(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        indegrees[y]++;
    }

    std::vector<int> sorted_vertices;
    std::queue<int> que;
    for (int i = 0; i < n; i++) {
        if (indegrees[i] != 0) {
            continue;
        }
        que.push(i);
    }

    while (!que.empty()) {
        int curr_vertex = que.front();
        que.pop();

        for (const auto &v : g[curr_vertex]) {
            indegrees[v]--;
            if (indegrees[v] == 0) {
                que.push(v);
            }
        }

        sorted_vertices.push_back(curr_vertex);
    }

    std::vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        int curr_vertex = sorted_vertices[i];
        for (const auto &v : g[curr_vertex]) {
            dp[v] = dp[curr_vertex] + 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = std::max(dp[i], ans);
    }

    std::cout << ans << std::endl;
    return 0;
}