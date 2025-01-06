#include <iostream>
#include <limits>
#include <string>
#include <vector>

int main() {
    constexpr int INF = 1e9;

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    std::vector dists(n, std::vector<std::pair<int, long long>>(n, {INF, INF}));
    for (int i = 0; i < n; i++) dists[i][i] = {0, 0};

    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'N') continue;
            dists[i][j] = {1, -a[j]};
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                const auto &[ik_cost, ik_value] = dists[i][k];
                const auto &[kj_cost, kj_value] = dists[k][j];
                dists[i][j] = std::min(dists[i][j], {ik_cost + kj_cost, ik_value + kj_value});
            }
        }
    }

    int q;
    std::cin >> q;
    while (q--) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        auto [cost, value] = dists[u][v];
        value = -value + a[u];
        if (cost == INF || value == INF) {
            std::cout << "Impossible" << std::endl;
        } else {
            std::cout << cost << ' ' << value << std::endl;
        }
    }
    return 0;
}