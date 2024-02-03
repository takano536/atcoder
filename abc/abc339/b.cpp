#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int h, w, n;
    std::cin >> h >> w >> n;

    std::vector<std::vector<bool>> grid(h, std::vector<bool>(w));
    int dir = 0;
    const std::vector<std::pair<int, int>> DIRS = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    std::pair<int, int> pos = {0, 0};
    for (int i = 0; i < n; i++) {
        grid[pos.first][pos.second] = !grid[pos.first][pos.second];
        dir += grid[pos.first][pos.second] ? 1 : -1;
        if (dir < 0) {
            dir = 3;
        }
        if (dir >= 4) {
            dir = 0;
        }
        pos.first = pos.first + DIRS[dir].first;
        pos.second = pos.second + DIRS[dir].second;
        if (pos.first < 0) {
            pos.first = h - 1;
        }
        if (pos.first >= h) {
            pos.first = 0;
        }
        if (pos.second < 0) {
            pos.second = w - 1;
        }
        if (pos.second >= w) {
            pos.second = 0;
        }
    }

    for (const auto &v : grid) {
        for (const auto &b : v) {
            std::cout << (b ? '#' : '.');
        }
        std::cout << std::endl;
    }
    return 0;
}