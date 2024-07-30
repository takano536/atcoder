#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

int main() {
    constexpr std::array<std::pair<int, int>, 4> DIRS = {
        std::make_pair(+1, +0),
        std::make_pair(-1, +0),
        std::make_pair(+0, +1),
        std::make_pair(+0, -1),
    };

    int h, w, y;
    std::cin >> h >> w >> y;

    std::vector a(h + 2, std::vector<int>(w + 2, -1));
    std::map<int, std::vector<std::pair<int, int>>> deadlines;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            std::cin >> a[i][j];
            deadlines[a[i][j]].emplace_back(i, j);
        }
    }

    std::vector has_sunk(h + 2, std::vector<bool>(w + 2));
    for (int i = 0; i < h + 2; i++) {
        has_sunk[i][0] = true;
        has_sunk[i][w + 1] = true;
    }
    for (int j = 0; j < w + 2; j++) {
        has_sunk[0][j] = true;
        has_sunk[h + 1][j] = true;
    }

    auto is_flowing = [&DIRS, &h, &w, &has_sunk](const int i, const int j) -> bool {
        for (const auto &[di, dj] : DIRS) {
            const auto ni = di + i;
            const auto nj = dj + j;
            if (ni < 0 || ni >= h + 2 || nj < 0 || nj >= w + 2) continue;
            if (has_sunk[ni][nj]) return true;
        }
        return false;
    };

    auto bfs = [&DIRS, &h, &w, &a, &has_sunk](std::queue<std::pair<int, int>> &que, const int y) -> int {
        int ret = 0;

        while (!que.empty()) {
            const auto [pi, pj] = que.front();
            que.pop();

            if (has_sunk[pi][pj]) continue;

            has_sunk[pi][pj] = true;
            ret++;

            for (const auto &[di, dj] : DIRS) {
                const auto ni = di + pi;
                const auto nj = dj + pj;

                if (ni < 0 || ni >= h + 2 || nj < 0 || nj >= w + 2) continue;
                if (has_sunk[ni][nj]) continue;
                if (a[ni][nj] > y) continue;

                que.emplace(ni, nj);
            }
        }

        return ret;
    };

    int ans = h * w;
    for (int curr_y = 1; curr_y <= y; curr_y++) {
        std::queue<std::pair<int, int>> que;
        for (const auto &[i, j] : deadlines[curr_y]) {
            if (is_flowing(i, j)) que.emplace(i, j);
        }
        ans -= bfs(que, curr_y);
        std::cout << ans << std::endl;
    }
    return 0;
}