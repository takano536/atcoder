#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(m), b(m);
    for (auto &in : a) {
        std::cin >> in;
        in--;
    }
    for (auto &in : b) {
        std::cin >> in;
        in--;
    }

    std::vector<std::vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        graph[a[i]].push_back(b[i]);
        graph[b[i]].push_back(a[i]);
    }

    const int NONE = -1;
    std::vector<int> colors(n, NONE);
    bool satisfies = true;

    auto dfs = [&](auto dfs, int sv, int color) -> void {
        colors[sv] = color;
        int next_color = (color + 1) % 2;
        for (auto nv : graph[sv]) {
            if (colors[nv] == NONE) {
                dfs(dfs, nv, next_color);
            } else if (colors[nv] == colors[sv]) {
                satisfies = false;
                return;
            }
        }
        return;
    };

    for (int i = 0; i < n; i++) {
        if (colors[i] == NONE) {
            dfs(dfs, i, 0);
        }
    }

    std::cout << (satisfies ? "Yes" : "No") << std::endl;
    return 0;
}