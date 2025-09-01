#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

int main() {
    constexpr std::array DIRS = {
        std::make_pair(+1, 0),
        std::make_pair(-1, 0),
        std::make_pair(0, +1),
        std::make_pair(0, -1),
    };
    constexpr int INF = 1e9;

    int h, w;
    std::cin >> h >> w;

    std::vector<std::string> a(h * 2 + 1);
    a[h] = std::string(w, '#');
    int si = 0, sj = 0, gi = 0, gj = 0;
    for (int i = 0; i < h; i++) {
        std::string s;
        std::cin >> s;
        a[i] = s, a[i + h + 1] = s;
        for (int j = 0; j < w; j++) {
            if (s[j] == 'S') si = i, sj = j;
            if (s[j] == 'G') gi = i, gj = j;
            if (s[j] != 'x' && s[j] != 'o') continue;
            a[i][j] = (s[j] == 'o' ? '.' : '#');
            a[i + h + 1][j] = (s[j] == 'o' ? '#' : '.');
        }
    }

    std::vector dists(h * 2 + 1, std::vector<int>(w, INF));
    dists[si][sj] = 0;
    std::queue<std::pair<int, int>> que;
    que.emplace(si, sj);
    while (!que.empty()) {
        const auto [pi, pj] = que.front();
        que.pop();
        for (const auto &[di, dj] : DIRS) {
            auto ni = pi + di;
            auto nj = pj + dj;
            if (ni < 0 || ni >= h * 2 + 1 || nj < 0 || nj > w) continue;
            if (a[ni][nj] == '?') ni += (ni >= h ? -h - 1 : +h + 1);
            if (a[ni][nj] == '#') continue;
            if (dists[ni][nj] != INF) continue;
            dists[ni][nj] = dists[pi][pj] + 1;
            que.emplace(ni, nj);
        }
    }

    const auto &ans = std::min(dists[gi][gj], dists[gi + h + 1][gj]);
    std::cout << (ans != INF ? ans : -1) << std::endl;
    return 0;
}