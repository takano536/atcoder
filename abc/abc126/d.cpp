#include <iostream>
#include <utility>
#include <vector>

int main() {
    constexpr int NA = -1;

    int n;
    std::cin >> n;

    std::vector tree(n, std::vector<std::pair<int, int>>());
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        tree[u].emplace_back(v, w);
        tree[v].emplace_back(u, w);
    }

    std::vector<int> is_black(n, NA);
    is_black[0] = true;

    auto dfs = [&tree, &is_black](auto &&self, const int u) -> void {
        for (const auto &[v, w] : tree[u]) {
            if (is_black[v] != NA) continue;
            is_black[v] = (w % 2 ? !is_black[u] : is_black[u]);
            self(self, v);
        }
    };

    dfs(dfs, 0);
    for (const auto &color : is_black) std::cout << color << std::endl;
    return 0;
}