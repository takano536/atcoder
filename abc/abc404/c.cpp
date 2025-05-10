#include <iostream>
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
        graph[b].push_back(a);
        indegrees[a]++, indegrees[b]++;
    }

    if (n != m) {
        std::cout << "No" << std::endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (indegrees[i] == 2) continue;
        std::cout << "No" << std::endl;
        return 0;
    }

    std::vector<bool> has_visited(n);
    bool is_satisfied = true;
    auto dfs = [&](auto &&f, const int sv, const int pv) {
        if (sv == 0 && has_visited[sv]) {
            for (int i = 0; i < n; i++) {
                if (!has_visited[i]) is_satisfied = false;
            }
            return;
        }
        if (has_visited[sv]) {
            is_satisfied = false;
            return;
        }

        has_visited[sv] = true;
        for (const auto nv : graph[sv]) {
            if (nv == pv) continue;
            f(f, nv, sv);
        }
        return;
    };

    dfs(dfs, 0, graph[0][0]);
    std::cout << (is_satisfied ? "Yes" : "No") << std::endl;
    return 0;
}