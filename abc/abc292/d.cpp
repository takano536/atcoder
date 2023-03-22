#include <atcoder/dsu>
#include <iostream>
#include <vector>
#include <utility>

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> edge(m);
    for (auto &e : edge) {
        std::cin >> e.first >> e.second;
        e.first--, e.second--;
    }

    atcoder::dsu union_find(n);
    for (const auto &e : edge){
        union_find.merge(e.first, e.second);
    }

    std::vector<int> vertex_count(n), edge_count(n);
    for (int v = 0; v < n; v++) {
        vertex_count[union_find.leader(v)]++;
    }
    for (const auto &e : edge) {
        edge_count[union_find.leader(e.first)]++;
    }

    bool satisfies = true;
    for (int v = 0; v < n; v++) {
        if (vertex_count[union_find.leader(v)] != edge_count[union_find.leader(v)]) {
            satisfies = false;
        }
    }

    std::cout << (satisfies ? "Yes" : "No") << std::endl;
    return 0;
}