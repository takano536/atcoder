#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    constexpr long long INF = 1e18;

    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<std::pair<int, int>, int>> bridges(m);
    std::vector graph(n, std::vector<std::pair<int, int>>());
    std::vector costs(n, std::vector<long long>(n, INF));
    for (auto &[uv, t] : bridges) {
        auto &[u, v] = uv;
        std::cin >> u >> v >> t;
        u--, v--;
        graph[u].emplace_back(v, t);
        graph[v].emplace_back(u, t);
        costs[u][v] = std::min<long long>(t, costs[u][v]);
        costs[v][u] = std::min<long long>(t, costs[v][u]);
    }
    for (int i = 0; i < n; i++) costs[i][i] = 0;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                costs[i][j] = std::min(costs[i][j], costs[i][k] + costs[k][j]);
            }
        }
    }

    int q;
    std::cin >> q;

    while (q--) {
        int k;
        std::cin >> k;
        std::vector<int> b(k);
        for (auto &bi : b) {
            std::cin >> bi;
            bi--;
        }

        long long ans = INF;
        do {
            for (int dirs = 0; dirs < (1 << k); dirs++) {
                int curr = 0;
                long long cost = 0;
                for (int i = 0; i < k; i++) {
                    const auto &[uv, t] = bridges[b[i]];
                    const auto &[u, v] = uv;
                    if (dirs & (1 << i)) {
                        cost += costs[curr][u] + t;
                        curr = v;
                    } else {
                        cost += costs[curr][v] + t;
                        curr = u;
                    }
                }
                cost += costs[curr][n - 1];
                ans = std::min(cost, ans);
            }
        } while (std::next_permutation(b.begin(), b.end()));

        std::cout << ans << std::endl;
    }
    return 0;
}