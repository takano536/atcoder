#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    int h, w;
    std::cin >> h >> w;

    std::vector<std::string> s(h);
    for (int i = 0; i < h; i++) {
        std::cin >> s[i];
    }

    const std::vector<std::pair<int, int>> DIRS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

    int ans = 0;
    std::vector<std::vector<bool>> visited(h, std::vector<bool>(w));
    auto dfs = [&](auto dfs, std::pair<int, int> &curr) -> void {
        auto [i, j] = curr;
        visited[i][j] = true;
        for (const auto &dir : DIRS) {
            int ni = i + dir.first;
            int nj = j + dir.second;
            if (ni < 0 || ni >= h || nj < 0 || nj >= w) {
                continue;
            }
            if (s[ni][nj] == '#' && !visited[ni][nj]) {
                std::pair<int, int> next = {ni, nj};
                dfs(dfs, next);
            }
        }
        return;
    };

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!visited[i][j] && s[i][j] == '#') {
                ans++;
                std::pair<int, int> curr = {i, j};
                dfs(dfs, curr);
            }
        }
    }

    std::cout << ans << std::endl;
    return 0;
}