#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <atcoder/dsu>

int main() {
    const std::vector<std::pair<int, int>> DIRS = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
        {1, 1},
        {1, -1},
        {-1, 1},
        {-1, -1},
    };

    int h, w;
    std::cin >> h >> w;

    std::vector<std::string> s(h);
    for (auto &in : s) {
        std::cin >> in;
    }

    atcoder::dsu unionfind(h * w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '.') {
                continue;
            }
            for (const auto &dir : DIRS) {
                int ni = i + dir.first;
                int nj = j + dir.second;
                if (ni < 0 || ni >= h || nj < 0 || nj >= w) {
                    continue;
                }
                if (s[ni][nj] == '.') {
                    continue;
                }
                unionfind.merge(i * w + j, ni * w + nj);
            }
        }
    }

    auto groups = unionfind.groups();
    int ans = 0;
    for (const auto &v : groups) {
        int i = v[0] / w;
        int j = v[0] % w;
        if (s[i][j] == '#') {
            ans++;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}