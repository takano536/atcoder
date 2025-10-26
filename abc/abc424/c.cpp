#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> graph(n);
    std::vector<int> starts;
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        if (a == 0 && b == 0) {
            starts.push_back(i);
            continue;
        }
        a--, b--;
        graph[a].push_back(i);
        graph[b].push_back(i);
    }

    int ans = 0;
    std::vector<bool> is_reachable(n);
    auto dfs = [&](auto &&f, int sv) -> void {
        if (!is_reachable[sv]) ans++;
        is_reachable[sv] = true;
        for (const auto &nv : graph[sv]) {
            if (is_reachable[nv]) continue;
            f(f, nv);
        }
        return;
    };
    for (const auto &sv : starts) dfs(dfs, sv);

    std::cout << ans << std::endl;
    return 0;
}