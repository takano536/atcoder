#include <array>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

#include <atcoder/dsu>

int main() {
    constexpr std::array<std::pair<int, int>, 6> VECS = {
        std::make_pair(-1, -1),
        std::make_pair(-1, 0),
        std::make_pair(0, -1),
        std::make_pair(0, +1),
        std::make_pair(+1, 0),
        std::make_pair(+1, +1),
    };

    constexpr int MAX_ABS = 1000;
    constexpr int CELL_H = MAX_ABS * 2 + 1;
    constexpr int CELL_W = MAX_ABS * 2 + 1;

    int n;
    std::cin >> n;

    auto pair2int = [CELL_H](int i, int j) { return i * CELL_H + j; };

    std::vector is_black(CELL_H, std::vector<bool>(CELL_W));
    std::map<int, int> coord2idx;
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        x += MAX_ABS, y += MAX_ABS;
        is_black[x][y] = true;
        coord2idx[pair2int(x, y)] = i;
    }

    atcoder::dsu union_find(n);
    for (int i = 0; i < CELL_H; i++) {
        for (int j = 0; j < CELL_W; j++) {
            if (!is_black[i][j]) continue;
            for (const auto &[vi, vj] : VECS) {
                const auto ni = i + vi;
                const auto nj = j + vj;
                if (ni < 0 || ni >= CELL_H || nj < 0 || nj >= CELL_W) continue;
                if (!is_black[ni][nj]) continue;
                union_find.merge(coord2idx[pair2int(ni, nj)], coord2idx[pair2int(i, j)]);
            }
        }
    }

    std::cout << union_find.groups().size() << std::endl;
}