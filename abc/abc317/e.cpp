#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

int main() {
    int h, w;
    std::cin >> h >> w;
    std::vector<std::string> a(h);
    std::pair<int, int> start, goal;
    for (int i = 0; i < h; i++) {
        std::cin >> a[i];
        if (a[i].find('S') != std::string::npos) {
            start = {i, a[i].find('S')};
        }
        if (a[i].find('G') != std::string::npos) {
            goal = {i, a[i].find('G')};
        }
    }

    const std::vector<std::pair<int, int>> DIR = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    auto replace = [&](int i, int j, char c) {
        if (i < 0 || i >= h || j < 0 || j >= w) {
            return;
        }

        std::pair<int, int> dir;
        switch (c) {
            case '>':
                dir = DIR[0];
                break;
            case 'v':
                dir = DIR[1];
                break;
            case '<':
                dir = DIR[2];
                break;
            case '^':
                dir = DIR[3];
                break;
            default:
                return;
        }
        while (true) {
            i += dir.first;
            j += dir.second;
            if (i < 0 || i >= h || j < 0 || j >= w) {
                return;
            }
            if (a[i][j] != '.' && a[i][j] != '!') {
                return;
            }
            a[i][j] = '!';
        }
    };

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            replace(i, j, a[i][j]);
        }
    }

    std::queue<std::pair<int, int>> que;
    que.push(start);
    std::vector<std::vector<int>> dist(h, std::vector<int>(w, -1));
    dist[start.first][start.second] = 0;
    while (!que.empty()) {
        auto [i, j] = que.front();
        que.pop();
        for (auto [di, dj] : DIR) {
            int ni = i + di, nj = j + dj;
            if (ni < 0 || ni >= h || nj < 0 || nj >= w) {
                continue;
            }
            if (a[ni][nj] != '.' && a[ni][nj] != 'G') {
                continue;
            }
            if (dist[ni][nj] != -1) {
                continue;
            }
            que.push({ni, nj});
            dist[ni][nj] = dist[i][j] + 1;
        }
    }

    std::cout << dist[goal.first][goal.second] << std::endl;
    return 0;
}