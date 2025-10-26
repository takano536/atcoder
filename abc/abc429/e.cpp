#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <ranges>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

int main() {
    constexpr int RECORD_NUM = 2;
    constexpr int INF = 1e9;
    constexpr int NA = -1;

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    std::string s;
    std::cin >> s;

    std::queue<std::tuple<int, int, int>> que;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'S') que.emplace(i, 0, i);
    }
    std::vector dists(n, std::array<std::pair<int, int>, RECORD_NUM>());
    for (int i = 0; i < n; i++) {
        const auto na = std::make_pair(NA, INF);
        const auto init_dist = s[i] == 'S' ? std::make_pair(i, 0) : na;
        dists[i] = std::array{init_dist, na};
    }

    while (!que.empty()) {
        const auto [start, dist, curr] = que.front();
        que.pop();

        for (const auto next : g[curr]) {
            const auto next_starts = dists[next] | std::views::keys;
            for (int i = 0; i < RECORD_NUM; i++) {
                const auto [_, next_dist] = dists[next][i];
                if (dist + 1 >= next_dist) continue;
                if (next_starts.front() == start || next_starts.back() == start) continue;

                dists[next].back() = {start, dist + 1};
                que.emplace(start, dist + 1, next);

                auto dist_iter = (dists[next] | std::views::values).begin();
                const auto dist_1st = *dist_iter;
                const auto dist_2nd = *std::next(dist_iter);
                if (dist_1st > dist_2nd) std::swap(dists[next][0], dists[next][1]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == 'S') continue;
        auto dist_iter = (dists[i] | std::views::values).begin();
        const auto dist_1st = *dist_iter;
        const auto dist_2nd = *std::next(dist_iter);
        std::cout << dist_1st + dist_2nd << std::endl;
    }
    return 0;
}