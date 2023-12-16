#include <iostream>
#include <set>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> graph(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    std::vector<bool> visited(n);
    auto dfs = [&](auto &&self, int curr, int &cnt) -> void {
        cnt++;
        visited[curr] = true;
        for (auto next : graph[curr]) {
            if (visited[next]) {
                continue;
            }
            self(self, next, cnt);
        }
        return;
    };

    if (graph[0].size() == 1) {
        std::cout << 1 << std::endl;
        return 0;
    }

    std::multiset<int> cnts;
    for (auto start : graph[0]) {
        visited[0] = true;
        int cnt = 0;
        dfs(dfs, start, cnt);
        cnts.insert(cnt);
    }

    int ans = 1;
    for (auto iter = cnts.begin(); std::next(iter) != cnts.end(); iter++) {
        ans += *iter;
    }

    std::cout << ans << std::endl;
    return 0;
}