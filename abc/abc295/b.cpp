#include <iostream>
#include <vector>
#include <string>
#include <queue>

int main() {
    struct ExplosionPlace {
        int r;
        int c;
        int dist;
    };
    
    int r, c;
    std::cin >> r >> c;

    std::vector<std::string> b(r);
    for (auto &s : b) {
        std::cin >> s;
    }

    std::vector<std::pair<int, int>> direction = {
        std::pair<int, int>(1, 0),
        std::pair<int, int>(-1, 0),
        std::pair<int, int>(0, 1),
        std::pair<int, int>(0, -1)
    };

    auto ans = b;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (b[i][j] == '.' || b[i][j] == '#') {
                continue;
            }

            std::string dist_str = {b[i][j]};
            int dist = std::stoi(dist_str);
            
            std::queue<ExplosionPlace> que;
            que.push({i, j, 0});

            while (!que.empty()) {
                auto curr_explosionplace = que.front();
                que.pop();
                ans[curr_explosionplace.r][curr_explosionplace.c] = '.';

                for (const auto& d : direction) {
                    auto next_explosionplace = curr_explosionplace;
                    next_explosionplace.r += d.first;
                    next_explosionplace.c += d.second;
                    next_explosionplace.dist++;

                    if (next_explosionplace.dist > dist) {
                        continue;
                    }
                    if (next_explosionplace.r < 0 || next_explosionplace.r >= r) {
                        continue;
                    }
                    if (next_explosionplace.c < 0 || next_explosionplace.c >= c) {
                        continue;
                    }

                    que.push(next_explosionplace);
                }
            }
        }
    }

    for (const auto &s : ans) {
        std::cout << s << std::endl;
    }
}