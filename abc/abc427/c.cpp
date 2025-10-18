#include <iostream>
#include <utility>
#include <vector>

int main() {
    constexpr int INF = 1e9;

    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> edges(m);
    for (auto &[u, v] : edges) {
        std::cin >> u >> v;
        u--, v--;
    }

    int ans = INF;
    for (int bit = 0; bit < (1 << n); bit++) {
        std::vector<bool> vertex_colors(n);
        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) vertex_colors[i] = true;
        }
        int deleting_count = 0;
        for (const auto &[u, v] : edges) {
            if (vertex_colors[u] == vertex_colors[v]) deleting_count++;
        }
        ans = std::min(ans, deleting_count);
    }

    std::cout << ans << std::endl;
    return 0;
}
