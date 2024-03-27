#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

int main() {
    int h, w;
    std::cin >> h >> w;
    std::vector<std::string> c(h);
    for (auto &ci : c) {
        std::cin >> ci;
    }

    const std::vector<std::pair<int, int>> DIRS = {{1, 0}, {0, 1}};
    std::queue<std::pair<int, int>> que;
    que.push({0, 0});
    std::vector dists(h, std::vector<int>(w));
    dists[0][0] = 1;
    int ans = 1;
    while (!que.empty()) {
        const auto curr = que.front();
        que.pop();
        for (const auto &dir : DIRS) {
            auto next = curr;
            next.first += dir.first;
            next.second += dir.second;
            if (next.first >= h || next.second >= w) {
                continue;
            }
            if (c[next.first][next.second] == '#' || dists[next.first][next.second] != 0) {
                continue;
            }
            dists[next.first][next.second] = std::max(dists[next.first][next.second], dists[curr.first][curr.second] + 1);
            ans = std::max(ans, dists[next.first][next.second]);
            que.push(next);
        }
    }

    std::cout << ans << std::endl;
    return 0;
}