#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

int main() {
    int h, w;
    std::cin >> h >> w;

    std::vector<std::string> g(h);
    for (auto &gi : g) std::cin >> gi;

    const std::map<char, std::pair<int, int>> DIRS = {
        {'U', {-1, 0}},
        {'D', {+1, 0}},
        {'L', {0, -1}},
        {'R', {0, +1}},
    };

    std::vector has_visited(h, std::vector<bool>(w));
    std::pair<int, int> curr = {0, 0};
    bool is_stoppable = true;
    while (true) {
        const auto [i, j] = curr;
        has_visited[i][j] = true;

        const auto [di, dj] = DIRS.at(g[i][j]);
        auto ni = i + di;
        auto nj = j + dj;

        if (ni < 0 || ni >= h || nj < 0 || nj >= w) break;

        if (has_visited[ni][nj]) {
            is_stoppable = false;
            break;
        }

        curr = {ni, nj};
    }

    if (is_stoppable) {
        std::cout << curr.first + 1 << ' ' << curr.second + 1 << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
    return 0;
}