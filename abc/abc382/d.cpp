#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> ans;
    auto dfs = [&](auto &&f, std::vector<int> &v) -> void {
        if (v.size() == static_cast<std::size_t>(n)) {
            ans.push_back(v);
            return;
        }

        int i_end = m - 10 * (n - v.size() - 1);
        for (int i = v.back() + 10; i <= i_end; i++) {
            v.push_back(i);
            f(f, v);
            v.pop_back();
        }
        return;
    };

    int i_end = m - 10 * (n - 1);
    for (int i = 1; i <= i_end; i++) {
        std::vector<int> v = {i};
        dfs(dfs, v);
    }

    std::cout << ans.size() << std::endl;
    for (const auto &v : ans) {
        for (const auto &e : v) std::cout << e << ' ';
        std::cout << std::endl;
    }
    return 0;
}