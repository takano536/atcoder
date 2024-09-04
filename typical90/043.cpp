#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

int main() {
    int h, w;
    std::cin >> h >> w;

    std::pair<int, int> start, goal;
    std::cin >> start.first >> start.second;
    std::cin >> goal.first >> goal.second;

    start.first--, start.second--;
    goal.first--, goal.second--;
    const auto &[si, sj] = start;
    const auto &[gi, gj] = goal;

    std::vector<std::string> s(h);
    for (auto &si : s) std::cin >> si;

    constexpr std::array<std::pair<int, int>, 4> DIRS = {
        std::make_pair(-1, 0),
        std::make_pair(0, +1),
        std::make_pair(+1, 0),
        std::make_pair(0, -1),
    };
    constexpr int INF = 1e9;

    std::vector costs(h, std::vector<int>(w, INF));
    std::queue<std::pair<int, int>> que;
    costs[si][sj] = 0;
    que.push(start);

    while (!que.empty()) {
        const auto [ci, cj] = que.front();
        que.pop();

        for (const auto &[di, dj] : DIRS) {
            if (ci + di >= h || ci + di < 0 || cj + dj >= w || cj + dj < 0) continue;
            if (s[ci + di][cj + dj] == '#') continue;
            if (costs[ci + di][cj + dj] == costs[ci][cj]) continue;

            auto ni = ci, nj = cj;
            while (ni + di < h && ni + di >= 0 && nj + dj < w && nj + dj >= 0 && s[ni + di][nj + dj] != '#') {
                ni += di;
                nj += dj;
                if (costs[ni][nj] != INF) continue;
                costs[ni][nj] = costs[ci][cj] + 1;
                que.emplace(ni, nj);
            }
        }
    }

    std::cout << costs[gi][gj] - 1 << std::endl;
    return 0;
}