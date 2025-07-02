#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

int main() {
    constexpr int INF = 1e9;
    constexpr int MIN_CYCLE_SIZE = 3;

    int n, m;
    std::cin >> n >> m;

    std::set<std::pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        if (a > b) std::swap(a, b);
        edges.emplace(a, b);
    }

    int ans = INF;
    std::vector<int> vertices(n);

    for (int i = 0; i < n; i++) vertices[i] = i;
    do {
        std::set<std::pair<int, int>> satisfied_edges;
        int cost = 0;
        for (int i = 0; i < n; i++) {
            int u = vertices[i];
            int v = vertices[(i + 1) % n];
            if (u > v) std::swap(u, v);
            if (!edges.contains({u, v})) cost++;
            satisfied_edges.emplace(u, v);
        }
        for (const auto &edge : edges) {
            if (!satisfied_edges.contains(edge)) cost++;
        }
        ans = std::min(cost, ans);
    } while (std::next_permutation(vertices.begin(), vertices.end()));

    for (int i = 0; i < n; i++) vertices[i] = i;
    do {
        for (int tail = 3; tail <= 5; tail++) {
            std::set<std::pair<int, int>> satisfied_edges;
            int cost = 0;
            for (int i = 0; i < tail; i++) {
                int u = vertices[i];
                int v = i == tail - 1 ? vertices[0] : vertices[i + 1];
                if (u > v) std::swap(u, v);
                if (!edges.contains({u, v})) cost++;
                satisfied_edges.emplace(u, v);
            }
            for (int i = tail; i < n; i++) {
                int u = vertices[i];
                int v = i == n - 1 ? vertices[tail] : vertices[i + 1];
                if (u > v) std::swap(u, v);
                if (!edges.contains({u, v})) cost++;
                satisfied_edges.emplace(u, v);
            }

            if (tail < MIN_CYCLE_SIZE || n - tail < MIN_CYCLE_SIZE) continue;

            for (const auto &edge : edges) {
                if (!satisfied_edges.contains(edge)) cost++;
            }
            ans = std::min(cost, ans);
        }
    } while (std::next_permutation(vertices.begin(), vertices.end()));

    std::cout << ans << std::endl;
    return 0;
}