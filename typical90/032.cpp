#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
        }
    }

    int m;
    std::cin >> m;
    std::vector<std::vector<bool>> is_hate(n, std::vector<bool>(n));
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        is_hate[x][y] = true;
        is_hate[y][x] = true;
    }

    std::vector<int> idxs(n);
    std::iota(idxs.begin(), idxs.end(), 0);

    const int INF = 1e9;
    int ans = INF;
    do {
        bool satisfies = true;
        int time = 0;
        for (auto idx_iter = idxs.begin(); std::next(idx_iter) != idxs.end(); idx_iter++) {
            if (is_hate[*idx_iter][*std::next(idx_iter)]) {
                satisfies = false;
                break;
            }
        }
        if (!satisfies) {
            continue;
        }

        for (int section = 0; auto idx : idxs) {
            time += a[idx][section++];
        }
        ans = std::min(ans, time);
    } while (std::ranges::next_permutation(idxs).found);

    std::cout << (ans == INF ? -1 : ans) << std::endl;
}