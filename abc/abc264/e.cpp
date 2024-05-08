#include <iostream>
#include <utility>
#include <vector>

#include <atcoder/dsu>

int main() {
    int n, m, e;
    std::cin >> n >> m >> e;

    std::vector<std::pair<int, int>> edges(e);
    for (auto &[u, v] : edges) {
        std::cin >> u >> v;
        u--, v--;
    }

    int q;
    std::cin >> q;

    std::vector<int> x(q);
    std::vector<int> has_cut(e);
    for (auto &xi : x) {
        std::cin >> xi;
        xi--;
        has_cut[xi] = true;
    }

    std::vector<bool> is_light(n + m);
    for (int i = n; i < n + m; i++) is_light[i] = true;
    int cnt = m;

    atcoder::dsu uf(n + m);

    auto update = [&uf, &cnt, &is_light](int v, int coef) {
        v = uf.leader(v);
        if (is_light[v]) cnt += uf.size(v) * coef;
    };

    auto merge = [&uf, &update, &is_light](int u, int v) {
        if (uf.same(u, v)) return;
        update(u, -1), update(v, -1);
        bool curr = is_light[uf.leader(u)] | is_light[uf.leader(v)];
        uf.merge(u, v);
        is_light[uf.leader(u)] = curr;
        update(u, 1);
    };

    for (int i = 0; const auto &[u, v] : edges) {
        if (!has_cut[i++]) merge(u, v);
    }

    std::vector<int> ans(q);
    for (int i = q - 1; i >= 0; i--) {
        ans[i] = cnt - m;
        auto [u, v] = edges[x[i]];
        merge(u, v);
    }

    for (const auto &x : ans) std::cout << x << std::endl;
    return 0;
}