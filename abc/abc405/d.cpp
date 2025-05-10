#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

int main() {
    constexpr int INF = 1e9;
    constexpr std::array DIRS = {
        std::make_tuple(0, 1, '<'),
        std::make_tuple(1, 0, '^'),
        std::make_tuple(0, -1, '>'),
        std::make_tuple(-1, 0, 'v'),
    };

    int h, w;
    std::cin >> h >> w;

    std::vector<std::string> s(h);
    for (auto &si : s) std::cin >> si;

    std::queue<std::pair<int, int>> que;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == 'E') que.emplace(i, j);
        }
    }

    auto ans = s;
    std::vector dists(h, std::vector(w, INF));
    while (!que.empty()) {
        const auto [i, j] = que.front();
        que.pop();

        for (const auto &[di, dj, chr] : DIRS) {
            const int ni = i + di;
            const int nj = j + dj;
            if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            if (s[ni][nj] == 'E' || s[ni][nj] == '#') continue;
            if (dists[ni][nj] != INF) continue;

            dists[ni][nj] = dists[i][j] + 1;
            ans[ni][nj] = chr;
            que.emplace(ni, nj);
        }
    }

    for (const auto &si : ans) std::cout << si << std::endl;
    return 0;
}