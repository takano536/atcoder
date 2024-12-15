#include <array>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int main() {
    constexpr std::array<std::pair<int, int>, 4> DIRS = {
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

    auto coord2id = [w](const int i, const int j) { return i * w + j; };
    auto id2coord = [w](const int id) { return std::make_pair(id / w, id % w); };

    std::priority_queue<
        std::pair<long long, int>,
        std::vector<std::pair<long long, int>>,
        std::greater<std::pair<long long, int>>
    > que;

    auto push = [&](const int i, const int j) {
        for (const auto &[di, dj] : DIRS) {
            const int ni = i + di, nj = j + dj;
            if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            if (has_visited[ni][nj]) continue;
            que.emplace(s[ni][nj], coord2id(ni, nj));
            has_visited[ni][nj] = true;
        }
    };
    push(p, q);

    while (!que.empty()) {
        const auto [curr_size, curr_id] = que.top();
        const auto [ci, cj] = id2coord(curr_id);
        que.pop();

        const long long max_size = ans / x - (ans % x == 0 ? 1 : 0);
        if (curr_size > max_size) continue;

        ans += curr_size;

        push(ci, cj);
    }

    std::cout << ans << std::endl;
    return 0;
}