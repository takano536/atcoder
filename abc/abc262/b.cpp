#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector is_connected(n, std::vector<int>(n));
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        is_connected[u][v] = true;
        is_connected[v][u] = true;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (!is_connected[i][j]) continue;
                if (!is_connected[j][k]) continue;
                if (!is_connected[k][i]) continue;
                ans++;
            }
        }
    }

    std::cout << ans << std::endl;
    return 0;
}