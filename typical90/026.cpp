#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> graph(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        std::cin >> a >> b;
        --a, --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    std::vector<int> colors(n, -1);
    std::vector<int> color_cnts(2);

    auto dfs = [&](auto dfs, int sv) -> void {
        for (auto nv : graph[sv]) {
            if (colors[nv] != -1) {
                continue;
            }
            colors[nv] = 1 - colors[sv];
            color_cnts[colors[nv]]++;
            dfs(dfs, nv);
        }
        return;
    };

    colors[0] = 0;
    color_cnts[0]++;
    dfs(dfs, 0);

    int max_color = color_cnts[0] > color_cnts[1] ? 0 : 1;
    for (int i = 0, cnt = 0; cnt < n / 2; i++) {
        if (colors[i] != max_color) {
            continue;
        }
        std::cout << i + 1 << ' ';
        cnt++;
    }
    std::cout << std::endl;
    return 0;
}