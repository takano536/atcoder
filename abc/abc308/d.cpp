#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
    int h, w;
    std::cin >> h >> w;

    std::vector<std::string> s(h);
    for (int i = 0; i < h; i++) {
        std::cin >> s[i];
    }

    const std::vector<int> dh = {0, 1, 0, -1};
    const std::vector<int> dw = {1, 0, -1, 0};
    const std::string snuke = "snuke";

    std::vector<std::vector<int>> dist(h, std::vector<int>(w, -1));
    std::queue<std::pair<std::pair<int, int>, int>> que;
    que.push(std::make_pair(std::make_pair(0, 0), 0));

    while (!que.empty()) {
        auto p = que.front();
        que.pop();

        int ch = p.first.first;
        int cw = p.first.second;
        int next_idx = (p.second + 1) % 5;

        for (int i = 0; i < 4; i++) {
            int nh = ch + dh[i];
            int nw = cw + dw[i];

            if (nh < 0 || nh >= h || nw < 0 || nw >= w) {
                continue;
            }

            if (s[nh][nw] != snuke[next_idx]) {
                continue;
            }

            if (dist[nh][nw] != -1) {
                continue;
            }

            dist[nh][nw] = dist[ch][cw] + 1;
            que.push(std::make_pair(std::make_pair(nh, nw), next_idx));
        }
    }

    std::cout << (dist[h - 1][w - 1] != -1 ? "Yes" : "No") << std::endl;
    return 0;
}