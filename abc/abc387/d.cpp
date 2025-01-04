#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

int main() {
    constexpr std::array<std::pair<int, int>, 4> DIRS = {
        std::make_pair(0, 1),
        std::make_pair(1, 0),
        std::make_pair(0, -1),
        std::make_pair(-1, 0),
    };

    constexpr int NA = -1;
    constexpr int INF = 1e9;

    int h, w;
    std::cin >> h >> w;

    std::vector<std::string> s(h);
    for (auto &si : s) std::cin >> si;

    std::pair<int, int> start, goal;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == 'S') start = std::make_pair(i, j);
            if (s[i][j] == 'G') goal = std::make_pair(i, j);
        }
    }

    int ans = INF;

    auto bfs = [&](std::queue<std::pair<std::pair<int, int>, std::pair<int, bool>>> &que, std::vector<std::vector<int>> &dist) {
        while (!que.empty()) {
            auto [coord, info] = que.front();
            auto [d, is_vertical] = info;
            que.pop();

            if (coord == goal) ans = std::min(ans, d);

            for (const auto &[di, dj] : DIRS) {
                if (is_vertical && di == 0) continue;
                if (!is_vertical && dj == 0) continue;

                int ni = coord.first + di;
                int nj = coord.second + dj;
                if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                if (s[ni][nj] == '#') continue;
                if (dist[ni][nj] != NA) continue;
                que.push(std::make_pair(std::make_pair(ni, nj), std::make_pair(d + 1, di == 0)));
                dist[ni][nj] = d + 1;
            }
        }
    };

    for (const auto &[di, dj] : DIRS) {
        std::queue<std::pair<std::pair<int, int>, std::pair<int, bool>>> que;
        std::vector<std::vector<int>> dist(h, std::vector<int>(w, NA));
        int ni = start.first + di;
        int nj = start.second + dj;
        if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
        if (s[ni][nj] == '#') continue;
        que.push(std::make_pair(std::make_pair(ni, nj), std::make_pair(1, di == 0)));
        dist[ni][nj] = 1;
        bfs(que, dist);
    }

    std::cout << (ans == INF ? -1 : ans) << std::endl;
    return 0;
}