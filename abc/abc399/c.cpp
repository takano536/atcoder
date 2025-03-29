#include <iostream>

#include <atcoder/dsu>

int main() {
    int n, m;
    std::cin >> n >> m;

    atcoder::dsu union_find(n);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        if (union_find.leader(u) == union_find.leader(v)) {
            ans++;
            continue;
        }
        union_find.merge(u, v);
    }

    std::cout << ans << std::endl;
    return 0;
}