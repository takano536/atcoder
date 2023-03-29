#include <iostream>
#include <vector>

#include <atcoder/dsu>

int main() {
    int n, m;
    std::cin >> n >> m;

    atcoder::dsu union_find(n);
    std::vector<int> degrees(n);
    bool satisfies = true;
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        degrees[u]++, degrees[v]++;
        if (degrees[u] > 2 || degrees[v] > 2) {
            satisfies = false;
        }

        if (union_find.leader(u) == union_find.leader(v)) {
            satisfies = false;
        }
        union_find.merge(u, v);
    }

    for (const auto &degree : degrees) {
        if (degree == 0) {
            satisfies = false;
        }
    }

    std::cout << (satisfies ? "Yes" : "No") << std::endl;
    return 0;
}