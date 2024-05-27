#include <array>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

#include <atcoder/dsu>

int main() {
    constexpr int MAX_COORD = 1000;
    constexpr int MAX_ID = (MAX_COORD * 2 + 1) * (MAX_COORD * 2 + 1) + 1;
    constexpr std::array<std::pair<int, int>, 6> DIRS = {
        std::make_pair(-1, -1),
        std::make_pair(-1, +0),
        std::make_pair(+0, -1),
        std::make_pair(+0, +1),
        std::make_pair(+1, +0),
        std::make_pair(+1, +1)
    };

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> black_coords;
    std::set<int> black_ids;
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        x += MAX_COORD, y += MAX_COORD;
        black_coords.push_back({x, y});
        black_ids.insert(x * MAX_COORD * 2 + y);
    }

    atcoder::dsu union_find(MAX_ID);
    for (const auto &[x, y] : black_coords) {
        int curr_id = x * MAX_COORD * 2 + y;

        for (const auto &dir : DIRS) {
            const auto [dx, dy] = dir;
            const int id = (x + dx) * MAX_COORD * 2 + (y + dy);
            if (id >= MAX_ID || id < 0) continue;
            if (!black_ids.contains(id)) continue;
            union_find.merge(curr_id, id);
        }
    }

    int ans = 0;
    for (const auto &group : union_find.groups()) {
        ans += (group.size() > 1 || black_ids.contains(*group.begin())) ? 1 : 0;
    }
    std::cout << ans << std::endl;
    return 0;
}