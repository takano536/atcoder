#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

int main() {
    int h, w, n;
    std::cin >> h >> w >> n;

    std::string t;
    std::cin >> t;

    std::vector<std::string> s(h);
    for (auto &si : s) std::cin >> si;

    const std::map<char, std::pair<int, int>> DIRS = {
        {'U', {-1, 0}},
        {'R', {0, +1}},
        {'D', {+1, 0}},
        {'L', {0, -1}},
    };

    auto is_conflict = [&](const std::pair<int, int> &start) -> bool {
        auto [ci, cj] = start;
        for (const auto &c : t) {
            const auto &[di, dj] = DIRS.at(c);
            const int ni = ci + di;
            const int nj = cj + dj;

            if (ni >= h || ni < 0 || nj >= w || nj < 0) return true;
            if (s[ni][nj] == '#') return true;

            ci = ni, cj = nj;
        }
        return false;
    };

    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') continue;
            if (!is_conflict({i, j})) ans++;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}