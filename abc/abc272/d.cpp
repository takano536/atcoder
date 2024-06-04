#include <array>
#include <cmath>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int main() {
    constexpr int M_MAX = 1e6;
    constexpr int NA = -1;
    constexpr std::array<std::pair<int, int>, 4> COEFS = {
        std::make_pair(+1, +1),
        std::make_pair(-1, +1),
        std::make_pair(+1, -1),
        std::make_pair(-1, -1)
    };

    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> dirs;
    for (int i = 0; i <= std::sqrt(M_MAX); i++) {
        for (int j = 0; j <= std::sqrt(M_MAX); j++) {
            if (i * i + j * j == m) dirs.push_back({i, j});
        }
    }

    std::vector dists(n, std::vector<int>(n, NA));
    dists[0][0] = 0;
    std::queue<std::pair<std::pair<int, int>, int>> que;
    que.push({{0, 0}, 0});

    auto write_dist = [&](const std::pair<int, int> &coord, const std::pair<int, int> &dir, int dist) {
        const auto [i, j] = coord;
        const auto [di, dj] = dir;

        for (const auto &[ci, cj] : COEFS) {
            const auto ni = i + di * ci;
            const auto nj = j + dj * cj;

            if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
            if (dists[ni][nj] != NA) continue;

            dists[ni][nj] = dist + 1;
            que.push({{ni, nj}, dist + 1});
        }
    };

    while (!que.empty()) {
        const auto [coord, dist] = que.front();
        que.pop();
        for (const auto &[di, dj] : dirs) write_dist(coord, {di, dj}, dist);
    }

    for (const auto &v : dists) {
        for (const auto &dist : v) std::cout << dist << ' ';
        std::cout << std::endl;
    }
    return 0;
}