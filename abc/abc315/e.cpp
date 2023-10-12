#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> c(n);
    std::vector<std::vector<int>> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
        for (int j = 0; j < c[i]; j++) {
            int s;
            std::cin >> s;
            p[i].push_back(s - 1);
        }
    }

    std::vector<int> ans;
    std::vector<bool> visited(n);
    auto dfs = [&](auto dfs, int id, std::vector<int> &pres) -> void {
        for (auto &pre : pres) {
            if (visited[pre]) {
                continue;
            }
            dfs(dfs, pre, p[pre]);
        }
        visited[id] = true;
        ans.push_back(id);
        return;
    };

    dfs(dfs, 0, p[0]);
    ans.pop_back();

    for (auto &a : ans) {
        std::cout << a + 1 << " ";
    }
    std::cout << std::endl;
    return 0;
}