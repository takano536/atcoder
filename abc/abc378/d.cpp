#include <array>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
    constexpr std::array<std::pair<int, int>, 4> VECS = {
        std::make_pair(0, 1),
        std::make_pair(0, -1),
        std::make_pair(1, 0),
        std::make_pair(-1, 0),
    };

    int h, w, k;
    std::cin >> h >> w >> k;

    std::vector<std::string> s(h);
    for (auto &si : s) std::cin >> si;

    long long ans = 0;
    auto dfs = [&](auto &&f, const std::pair<int, int> &coords, int cost, std::vector<std::vector<bool>> &has_visited) {
        const auto &[i, j] = coords;
        if (i < 0 || i >= h || j < 0 || j >= w) return;
        if (s[i][j] == '#' || has_visited[i][j]) return;

        has_visited[i][j] = true;

        if (cost == k) {
            ans++;
        } else {
            for (const auto &[di, dj] : VECS) {
                int ni = i + di;
                int nj = j + dj;
                f(f, {ni, nj}, cost + 1, has_visited);
            }
        }

        has_visited[i][j] = false;
    };

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::vector<int> path;
            std::vector<std::vector<bool>> has_visited(h, std::vector<bool>(w, false));
            dfs(dfs, {i, j}, 0, has_visited);
        }
    }

    std::cout << ans << std::endl;
    return 0;
}