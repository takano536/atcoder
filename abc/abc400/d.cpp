#include <array>
#include <deque>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
    constexpr int INF = 1e9;
    constexpr std::array DIRS = {
        std::make_pair(0, +1),
        std::make_pair(0, +2),
        std::make_pair(+1, 0),
        std::make_pair(+2, 0),
        std::make_pair(0, -1),
        std::make_pair(0, -2),
        std::make_pair(-1, 0),
        std::make_pair(-2, 0),
    };

    int h, w;
    std::cin >> h >> w;

    std::vector<std::string> s(h);
    for (auto &si : s) std::cin >> si;

    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    a--, b--, c--, d--;

    std::vector costs(h, std::vector(w, INF));
    costs[a][b] = 0;
    std::deque<std::pair<int, int>> que;
    que.emplace_front(a, b);

    while (!que.empty()) {
        const auto [i, j] = que.front();
        que.pop_front();

        for (const auto &[di, dj] : DIRS) {
            const auto ni = i + di;
            const auto nj = j + dj;

            if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;

            if (s[ni][nj] == '.' && costs[ni][nj] > costs[i][j] && std::max(std::abs(di), std::abs(dj)) == 1) {
                costs[ni][nj] = costs[i][j];
                que.emplace_front(ni, nj);
            }
            if (s[ni][nj] == '#' && costs[ni][nj] > costs[i][j] + 1) {
                costs[ni][nj] = costs[i][j] + 1;
                que.emplace_back(ni, nj);
            }
        }
    }

    std::cout << costs[c][d] << std::endl;
    return 0;
}