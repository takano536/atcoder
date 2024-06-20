#include <iostream>

#include <atcoder/dsu>

int main() {
    int n, m;
    std::cin >> n >> m;

    atcoder::dsu union_find(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        union_find.merge(u, v);
    }

    std::cout << union_find.groups().size() << std::endl;
    return 0;
}