#include <iostream>
#include <queue>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector graph(n, std::vector<int>());
    std::vector<int> indegrees(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        indegrees[b]++;
    }

    std::vector<int> ans;
    std::priority_queue<int, std::vector<int>, std::greater<int>> que;
    for (int i = 0; i < n; i++) {
        if (indegrees[i] == 0) {
            que.push(i);
        }
    }

    while (!que.empty()) {
        int v = que.top();
        que.pop();

        for (auto u : graph[v]) {
            indegrees[u]--;
            if (indegrees[u] == 0) {
                que.push(u);
            }
        }
        ans.push_back(v);
    }

    if (static_cast<int>(ans.size()) != n) {
        std::cout << -1 << std::endl;
        return 0;
    }

    for (const auto v : ans) {
        std::cout << v + 1 << ' ';
    }
    std::cout << std::endl;
    return 0;
}