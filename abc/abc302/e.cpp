#include <iostream>
#include <set>
#include <stdexcept>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<std::set<int>> graph(n);
    int ans = n;
    while (q--) {
        int op;
        std::cin >> op;
        switch (op) {
            case 1: {
                int u, v;
                std::cin >> u >> v;
                u--, v--;
                if (graph[u].empty()) ans--;
                graph[u].insert(v);
                if (graph[v].empty()) ans--;
                graph[v].insert(u);
                break;
            }
            case 2: {
                int v;
                std::cin >> v;
                v--;
                for (const auto &u : graph[v]) {
                    graph[u].erase(v);
                    if (graph[u].empty()) ans++;
                }
                if (!graph[v].empty()) graph[v].clear(), ans++;
                break;
            }
            default:
                throw std::runtime_error("invalid input");
        }
        std::cout << ans << std::endl;
    }
    return 0;
}