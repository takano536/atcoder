#include <iostream>
#include <utility>
#include <vector>

#include <atcoder/dsu>

int main() {
    constexpr int NA = -1;
    constexpr int MAX_BIT = 30;

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int>>> graph(n);
    atcoder::dsu union_find(n);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        std::cin >> x >> y >> z;
        x--, y--;

        if (x == y && z != 0) {
            std::cout << -1 << std::endl;
            return 0;
        }

        union_find.merge(x, y);
        graph[x].emplace_back(y, z);
        graph[y].emplace_back(x, z);
    }

    auto groups = union_find.groups();

    std::vector bit_colors(n, NA);
    std::vector bit_color_cnts(groups.size(), std::vector(MAX_BIT + 1, 0));
    bool is_satisfied = true;
    auto dfs = [&](auto &&f, const int curr, const int color, const int group_id) -> void {
        bit_colors[curr] = color;
        for (int i = 0; i <= MAX_BIT; i++) {
            if (color & (1 << i)) bit_color_cnts[group_id][i]++;
        }
        for (const auto &[next, weight] : graph[curr]) {
            if (bit_colors[next] != NA) {
                if ((bit_colors[next] ^ color) != weight) is_satisfied = false;
                continue;
            }
            f(f, next, color ^ weight, group_id);
        }
        return;
    };

    for (std::size_t i = 0; i < groups.size(); i++) dfs(dfs, groups[i].front(), 0, i);
    if (!is_satisfied) {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::vector<int> a(n);
    for (int i = 0; i <= MAX_BIT; i++) {
        for (std::size_t j = 0; j < groups.size(); j++) {
            const bool is_inverse = bit_color_cnts[j][i] > static_cast<int>(groups[j].size()) / 2;
            for (const auto &curr : groups[j]) {
                if (bit_colors[curr] == NA) continue;
                if (is_inverse) bit_colors[curr] ^= (1 << i);
                a[curr] |= (bit_colors[curr] & (1 << i));
            }
        }
    }

    for (const auto &ai : a) std::cout << ai << ' ';
    std::cout << std::endl;
    return 0;
}