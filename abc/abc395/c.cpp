#include <iostream>
#include <map>
#include <vector>

int main() {
    constexpr int INF = 1e9;

    int n;
    std::cin >> n;

    std::map<int, std::vector<int>> idxes;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        idxes[a].push_back(i);
    }

    int ans = INF;
    for (const auto &[_, v] : idxes) {
        if (v.size() == 1) continue;
        for (std::size_t i = 0; i < v.size() - 1; i++) ans = std::min(ans, v[i + 1] - v[i] + 1);
    }

    std::cout << (ans == INF ? -1 : ans) << std::endl;
    return 0;
}