#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

int main() {
    int h, w;
    std::cin >> h >> w;

    std::vector<std::string> s(h);
    for (int i = 0; i < h; i++) {
        std::cin >> s[i];
    }

    const std::vector<std::pair<int, int>> DIRS = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0},
        {1, 1},
        {-1, -1},
        {1, -1},
        {-1, 1},
    };

    std::vector<std::vector<bool>> visited(h, std::vector<bool>(w));
    auto bfs = [&](int si, int sj) {
        std::queue<std::pair<int, int>> que;
        que.push({si, sj});
        visited[si][sj] = true;

        while (!que.empty()) {
            auto [i, j] = que.front();
            que.pop();
            for (const auto &dir : DIRS) {
                int ni = i + dir.first;
                int nj = j + dir.second;
                if (ni < 0 || ni >= h || nj < 0 || nj >= w) {
                    continue;
                }
                if (s[ni][nj] == '#' && !visited[ni][nj]) {
                    que.push({ni, nj});
                    visited[ni][nj] = true;
                }
            }
        }
    };

    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!visited[i][j] && s[i][j] == '#') {
                ans++;
                bfs(i, j);
            }
        }
    }

    std::cout << ans << std::endl;
    return 0;
}