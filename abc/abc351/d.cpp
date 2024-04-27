#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

int main() {
    int h, w;
    std::cin >> h >> w;

    std::vector<std::string> s(h);
    for (auto &si : s) {
        std::cin >> si;
    }

    const std::vector<std::pair<int, int>> DIRS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    std::vector<std::vector<bool>> is_movable(h, std::vector<bool>(w, true));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') {
                is_movable[i][j] = false;
                continue;
            }
            for (const auto &dir : DIRS) {
                int ni = i + dir.first;
                int nj = j + dir.second;
                if (ni < 0 || ni >= h || nj < 0 || nj >= w) {
                    continue;
                }
                if (s[ni][nj] == '#') {
                    is_movable[i][j] = false;
                }
            }
        }
    }

    std::vector is_visited(h, std::vector<bool>(w));
    auto count_degree = [&](auto f, int i, int j, int &degree, std::set<int> &reached_coords) -> void {
        if (is_visited[i][j] || reached_coords.contains(i * w + j)) {
            return;
        }
        if (s[i][j] == '#') {
            return;
        }
        reached_coords.insert(i * w + j);
        degree++;
        if (!is_movable[i][j]) {
            return;
        }
        is_visited[i][j] = true;
        for (const auto &dir : DIRS) {
            int ni = i + dir.first;
            int nj = j + dir.second;
            if (ni < 0 || ni >= h || nj < 0 || nj >= w) {
                continue;
            }
            if (is_visited[ni][nj] || reached_coords.contains(ni * w + nj)) {
                continue;
            }
            f(f, ni, nj, degree, reached_coords);
        }
        return;
    };

    int ans = 1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!is_movable[i][j]) {
                continue;
            }
            int degree = 0;
            std::set<int> reached_coords;
            count_degree(count_degree, i, j, degree, reached_coords);
            ans = std::max(ans, degree);
        }
    }
    std::cout << ans << std::endl;
    return 0;
}