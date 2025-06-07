#include <iostream>
#include <utility>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> x(n);
    for (auto &xi : x) std::cin >> xi;

    std::vector graph(n, std::vector<std::pair<int, int>>());
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    long long ans = 0;
    auto dfs = [&](auto &&self, int u, int p = -1) -> void {
        for (const auto &[v, w] : graph[u]) {
            if (v == p) continue;
            self(self, v, u);
            ans += static_cast<long long>(std::abs(x[v])) * w;
            x[u] += x[v];
        }
    };

    dfs(dfs, 0);
    std::cout << ans << std::endl;
}