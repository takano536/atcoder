#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <set>

int main() {
    constexpr int INF = std::numeric_limits<int>::max();

    int n, m;
    std::cin >> n >> m;
    std::map<int, std::set<int>> w_coords, b_coords;
    for (int i = 0; i < m; i++) {
        int x, y;
        char c;
        std::cin >> x >> y >> c;
        (c == 'B' ? b_coords[x] : w_coords[x]).insert(y);
    }

    bool is_satisfied = true;
    int w_upper = INF;
    auto w_iter = w_coords.begin();

    for (auto b_iter = b_coords.begin(); b_iter != b_coords.end(); b_iter++) {
        const auto &[x, _] = *b_iter;
        const auto b_lower = *std::ranges::max_element(b_iter->second);

        while (w_iter != w_coords.end() && x >= w_iter->first) {
            w_upper = std::min(*std::ranges::min_element(w_iter->second), w_upper);
            if (w_iter != w_coords.end()) w_iter++;
        }

        if (b_lower >= w_upper) is_satisfied = false;
    }

    std::cout << (is_satisfied ? "Yes" : "No") << std::endl;
    return 0;
}