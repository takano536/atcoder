#include <iostream>
#include <map>
#include <utility>
#include <vector>

int main() {
    constexpr int INF = 1e9;

    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> a(n);
    std::vector<int> b(m);
    for (int i = 0; auto &[ai, idx] : a) std::cin >> ai, idx = i++;
    for (auto &bi : b) std::cin >> bi;

    std::map<int, int> limits;
    int curr_min = INF;
    for (const auto &[ai, i] : a) {
        if (ai >= curr_min) continue;
        curr_min = ai;
        limits[-ai] = i;
    }

    for (auto &bi : b) {
        if (bi < curr_min) {
            std::cout << -1 << std::endl;
            continue;
        }
        auto iter = limits.lower_bound(-bi);
        std::cout << iter->second + 1 << std::endl;
    }

    return 0;
}