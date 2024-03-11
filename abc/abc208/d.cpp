#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    const int INF = 1e9;
    std::vector graph(n, std::vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        graph[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--, b--;
        graph[a][b] = c;
    }

    long long ans = 0;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
                if (graph[i][j] != INF) {
                    ans += graph[i][j];
                }
            }
        }
    }

    std::cout << ans << std::endl;
    return 0;
}