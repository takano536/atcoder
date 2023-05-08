#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

std::vector<std::vector<int>> search_maze(const std::vector<std::string> &field, int sx, int sy) {
    const std::vector<std::pair<int, int>> DIRECTIONS{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    const int MAX_DIST = 1e9;

    int width = field[0].size();
    int height = field.size();

    std::vector<std::vector<int>> dist(height, std::vector<int>(width, -1));
    std::queue<std::pair<int, int>> que;
    int res = 1e9;
    dist[sx][sy] = 0;
    que.push(std::make_pair(sx, sy));

    while (!que.empty()) {
        std::pair<int, int> curr_pos = que.front();
        que.pop();

        for (int d = 0; d < 4; d++) {
            auto next_pos = curr_pos;
            next_pos.first += DIRECTIONS[d].first;
            next_pos.second += DIRECTIONS[d].second;
            if (next_pos.first < 0 || next_pos.first >= height || next_pos.second < 0 || next_pos.second >= width) {
                continue;
            }
            if (field[next_pos.first][next_pos.second] == '#') {
                continue;
            }

            if (dist[next_pos.first][next_pos.second] != -1) {
                continue;
            }
            que.push(std::make_pair(next_pos.first, next_pos.second));
            dist[next_pos.first][next_pos.second] = dist[curr_pos.first][curr_pos.second] + 1;
            res = std::max(dist[next_pos.first][next_pos.second], res);
        }
    }

    return dist;
}

int main() {
    int h, w;
    std::cin >> h >> w;

    std::vector<std::string> s(h);
    for (auto &str : s) {
        std::cin >> str;
    }

    auto dist = search_maze(s, 0, 0);

    if (dist[h - 1][w - 1] == -1) {
        std::cout << -1 << std::endl;
        return 0;
    }

    int score = -(dist[h - 1][w - 1] + 1);
    for (const auto &str : s) {
        for (const auto &chr : str) {
            score += static_cast<int>(chr == '.');
        }
    }

    std::cout << score << std::endl;
    return 0;
}