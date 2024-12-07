#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

int main() {
    constexpr std::array<std::pair<int, int>, 4> DIRS = {
        std::make_pair(0, 1),
        std::make_pair(0, -1),
        std::make_pair(1, 0),
        std::make_pair(-1, 0),
    };

    int h, w, d;
    std::cin >> h >> w >> d;
    d++;

    std::vector<std::string> s(h);
    for (auto &si : s) std::cin >> si;

    int ans = 0;
    std::vector dists(h, std::vector<int>(w));

    std::queue<std::pair<std::pair<int, int>, int>> que;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == 'H') que.emplace(std::make_pair(i, j), 1);
        }
    }

    while (!que.empty()) {
        const auto [coord, dist] = que.front();
        que.pop();
        const auto [i, j] = coord;
        if (s[i][j] == '#') continue;
        if (dists[i][j] != 0) continue;
        dists[i][j] = dist;
        ans++;
        if (dist >= d) continue;
        for (const auto &[di, dj] : DIRS) {
            const int ni = i + di;
            const int nj = j + dj;
            if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            if (s[ni][nj] == '#') continue;
            if (dists[ni][nj] != 0) continue;
            que.emplace(std::make_pair(ni, nj), dist + 1);
        }
    }

    std::cout << ans << std::endl;
    return 0;
}