#include <array>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

int main() {
    std::array<std::pair<int, int>, 4> DIRS = {
        std::make_pair(0, 1),
        std::make_pair(0, -1),
        std::make_pair(1, 0),
        std::make_pair(-1, 0),
    };

    int h, w, x;
    std::cin >> h >> w >> x;

    int p, q;
    std::cin >> p >> q;
    p--, q--;

    std::vector s(h, std::vector<long long>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::cin >> s[i][j];
        }
    }

    long long ans = s[p][q];
    std::vector has_visited(h, std::vector<bool>(w));
    has_visited[p][q] = true;

    auto coord2id = [&](int i, int j) { return i * w + j; };
    auto id2coord = [&](int id) { return std::make_pair(id / w, id % w); };

    std::multiset<long long> que;
    std::map<long long, std::vector<int>> size2id;
    for (auto [di, dj] : DIRS) {
        int ni = p + di, nj = q + dj;
        if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
        que.insert(-s[ni][nj]);
        size2id[s[ni][nj]].push_back(coord2id(ni, nj));
        has_visited[ni][nj] = true;
    }

    while (!que.empty()) {
        auto iter = que.lower_bound(-ans / x);
        if (iter == que.end()) break;
        if (ans % x == 0 && -*iter == ans / x) {
            while (iter != que.end() && ans / x < -*iter) iter++;
            if (iter == que.end() || ans / x >= -*iter) break;
        }
        auto size = -*iter;
        que.erase(iter);
        auto coord = id2coord(size2id[size].back());
        size2id[size].pop_back();

        ans += size;
        for (auto [di, dj] : DIRS) {
            int ni = coord.first + di, nj = coord.second + dj;
            if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            if (has_visited[ni][nj]) continue;
            que.insert(-s[ni][nj]);
            size2id[s[ni][nj]].push_back(coord2id(ni, nj));
            has_visited[ni][nj] = true;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}