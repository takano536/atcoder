#include <algorithm>
#include <iostream>
#include <set>

#include <atcoder/dsu>

int main() {
    int n, m;
    std::cin >> n >> m;

    atcoder::dsu uf(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        uf.merge(u, v);
    }

    std::set<std::pair<int, int>> bad_edges;
    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        auto x_leader = uf.leader(x);
        auto y_leader = uf.leader(y);
        bad_edges.insert({x_leader, y_leader});
        bad_edges.insert({y_leader, x_leader});
    }

    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        int p, q;
        std::cin >> p >> q;
        p--, q--;
        auto p_leader = uf.leader(p);
        auto q_leader = uf.leader(q);
        std::cout << (bad_edges.find({p_leader, q_leader}) == bad_edges.end() ? "Yes" : "No") << std::endl;
    }
    return 0;
}