#include <iostream>
#include <utility>
#include <vector>

#include <atcoder/dsu>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector graph(n, std::vector<int>());
    atcoder::dsu union_find(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        union_find.merge(u, v);
    }

    std::vector<bool> colors(n);
    std::vector<bool> has_visited(n);
    std::vector<bool> is_bipartite(n, true);
    auto dfs = [&](auto f, int from, bool color, std::pair<int, int> &cnts) -> void {
        auto &[black_cnt, white_cnt] = cnts;
        colors[from] = color;
        has_visited[from] = true;
        (color ? black_cnt : white_cnt)++;
        for (const auto &to : graph[from]) {
            if (has_visited[to]) {
                if (colors[to] == colors[from]) is_bipartite[union_find.leader(from)] = false;
                continue;
            }
            f(f, to, !color, cnts);
        }
    };

    int bipartite_vertex_cnt = 0;
    std::vector<std::pair<int, int>> color_cnts(n);
    for (int i = 0; i < n; i++) {
        if (has_visited[i]) continue;

        auto leader = union_find.leader(i);
        std::pair<int, int> cnts;
        dfs(dfs, i, 0, cnts);
        if (is_bipartite[leader]) color_cnts[leader] = cnts, bipartite_vertex_cnt += union_find.size(leader);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (!is_bipartite[union_find.leader(i)]) {
            std::cout << 0 << std::endl;
            return 0;
        }

        auto leader = union_find.leader(i);
        ans += bipartite_vertex_cnt - union_find.size(leader);

        if (union_find.size(i) == 1) continue;

        const auto &[black_cnt, white_cnt] = color_cnts[leader];
        int cnt = (colors[i] ? white_cnt : black_cnt);
        for (const auto &to : graph[i]) {
            if (colors[i] != colors[to]) cnt--;
        }
        ans += cnt;
    }

    std::cout << ans / 2 << std::endl;
    return 0;
}