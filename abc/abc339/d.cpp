#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

int main() {
    const int INF = 1e9;
    const int PLAYER_NUM = 2;
    const std::array<std::pair<int, int>, 4> DIRS = {
        std::make_pair(-1, 0),
        std::make_pair(0, 1),
        std::make_pair(1, 0),
        std::make_pair(0, -1),
    };

    int n;
    std::cin >> n;

    std::vector<std::string> s(n);
    for (auto &si : s) {
        std::cin >> si;
    }
    int h = s.size();
    int w = s[0].size();

    std::array<std::pair<int, int>, PLAYER_NUM> start_coords;
    auto iter = start_coords.begin();
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == 'P') {
                *iter = {i, j};
                iter++;
                s[i][j] = '.';
            }
        }
    }

    auto coords2id = [h, w](const std::array<std::pair<int, int>, PLAYER_NUM> &coords) -> int {
        int id = 0;
        for (const auto &coord : coords) {
            id = id * h + coord.first;
            id = id * w + coord.second;
        }
        return id;
    };
    auto id2coords = [h, w](int id) -> std::array<std::pair<int, int>, PLAYER_NUM> {
        std::array<std::pair<int, int>, PLAYER_NUM> coords;
        for (auto iter = std::rbegin(coords); iter != std::rend(coords); iter++) {
            iter->second = id % w, id /= w;
            iter->first = id % h, id /= h;
        }
        return coords;
    };

    std::vector<int> dists(h * w * h * w, INF);
    int start_id = coords2id(start_coords);
    dists[start_id] = 0;
    std::queue<int> que;
    que.push(start_id);

    auto move = [&s, h, w](std::array<std::pair<int, int>, PLAYER_NUM> &coords, const std::pair<int, int> &dir) -> void {
        for (auto &coord : coords) {
            auto [next_1st, next_2nd] = coord;
            next_1st += dir.first, next_2nd += dir.second;
            if (next_1st < 0 || next_1st > h - 1) {
                continue;
            }
            if (next_2nd < 0 || next_2nd > w - 1) {
                continue;
            }
            if (s[next_1st][next_2nd] == '#') {
                continue;
            }
            coord = {next_1st, next_2nd};
        }
    };

    while (!que.empty()) {
        auto curr_id = que.front();
        auto curr_coords = id2coords(curr_id);
        que.pop();

        for (const auto &dir : DIRS) {
            auto next_coords = curr_coords;
            move(next_coords, dir);
            auto next_id = coords2id(next_coords);
            if (dists[next_id] != INF) {
                continue;
            }
            dists[next_id] = dists[curr_id] + 1;
            que.push(next_id);
        }
    }

    int ans = INF;
    for (int id = 0; id < h * w * h * w; id++) {
        if (dists[id] == INF) {
            continue;
        }
        auto coords = id2coords(id);

        bool is_satisfied = true;
        for (int i = 0; i < PLAYER_NUM - 1; i++) {
            if (coords[i] != coords[i + 1]) {
                is_satisfied = false;
            }
        }
        if (is_satisfied) {
            ans = std::min(ans, dists[id]);

#ifndef ONLINE_JUDGE
            for (const auto &coord : coords) {
                std::cout << coord.first << ' ' << coord.second << "   ";
            }
            std::cout << dists[id] << std::endl;
#endif
        }
    }

    std::cout << (ans == INF ? -1 : ans) << std::endl;
    return 0;
}