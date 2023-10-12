#include <algorithm>
#include <iostream>
#include <vector>

#include <atcoder/dsu>

int main() {
    const std::vector<std::pair<int, int>> DIRS = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0},
    };

    int h, w;
    std::cin >> h >> w;

    int q;
    std::cin >> q;

    atcoder::dsu union_find(h * w);
    std::vector<std::vector<bool>> is_red(h, std::vector<bool>(w));
    auto coord2idx = [&w](const std::pair<int, int> &coord) -> int {
        return coord.first * w + coord.second;
    };
    auto merge = [&](const std::pair<int, int> &coord) -> void {
        for (const auto &dir : DIRS) {
            int first = coord.first + dir.first;
            int second = coord.second + dir.second;
            if (0 > first || first >= h || 0 > second || second >= w) {
                continue;
            }
            if (!is_red[first][second]) {
                continue;
            }
            union_find.merge(coord2idx(coord), coord2idx({first, second}));
        }
        return;
    };

    for (int i = 0; i < q; i++) {
        int t;
        std::cin >> t;

        switch (t) {
            case 1: {
                int r, c;
                std::cin >> r >> c;
                r--, c--;
                is_red[r][c] = true;
                merge({r, c});
                break;
            }
            case 2: {
                int ra, ca, rb, cb;
                std::cin >> ra >> ca >> rb >> cb;
                ra--, ca--, rb--, cb--;
                bool is_merge = (union_find.leader(coord2idx({ra, ca})) == union_find.leader(coord2idx({rb, cb})));
                is_merge = is_red[ra][ca] && is_red[rb][cb] && is_merge;
                std::cout << (is_merge ? "Yes" : "No") << std::endl;
                break;
            }
        }
    }
    return 0;
}