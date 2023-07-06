#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include <atcoder/modint>

int main() {
    int h, w;
    std::cin >> h >> w;

    std::vector<std::string> a(h);
    for (auto &input : a) {
        std::cin >> input;
    }

    const std::vector<std::pair<int, int>> DIRECTION = {{1, 0}, {0, 1}};
    std::vector<std::vector<int>> dist(h, std::vector<int>(w, -1));
    dist[0][0] = 0;
    std::queue<std::pair<int, int>> que;
    que.push({0, 0});

    std::vector<std::vector<atcoder::modint1000000007>> dp(h, std::vector<atcoder::modint1000000007>(w));
    dp[0][0] = 1;

    while (!que.empty()) {
        auto prev = que.front();
        que.pop();

        for (const auto &dir : DIRECTION) {
            auto curr = prev;
            curr.first += dir.first;
            curr.second += dir.second;

            if (curr.first < 0 || curr.first >= h) {
                continue;
            }
            if (curr.second < 0 || curr.second >= w) {
                continue;
            }
            if (a[curr.first][curr.second] == '#') {
                continue;
            }
            dp[curr.first][curr.second] += dp[prev.first][prev.second];

            if (dist[curr.first][curr.second] != -1) {
                continue;
            }

            dist[curr.first][curr.second] = dist[prev.first][prev.second] + 1;
            que.push(curr);
        }
    }

    std::cout << dp[h - 1][w - 1].val() << std::endl;
    return 0;
}