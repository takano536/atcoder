#include <iostream>
#include <stdexcept>
#include <vector>

#include <atcoder/dsu>

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<bool> is_black(n);
    std::vector<int> black_counts(n);
    atcoder::dsu union_find(n);

    while (q--) {
        int op;
        std::cin >> op;
        switch (op) {
            case 1: {
                int u, v;
                std::cin >> u >> v;
                u--, v--;
                if (union_find.same(u, v)) continue;
                const auto u_leader = union_find.leader(u);
                const auto v_leader = union_find.leader(v);
                const auto merged_count = black_counts[u_leader] + black_counts[v_leader];
                black_counts[u_leader] = 0, black_counts[v_leader] = 0;
                union_find.merge(u, v);
                black_counts[union_find.leader(u)] = merged_count;
                break;
            }
            case 2: {
                int v;
                std::cin >> v;
                v--;
                is_black[v] = !is_black[v];
                black_counts[union_find.leader(v)] += (is_black[v] ? +1 : -1);
                break;
            }
            case 3: {
                int v;
                std::cin >> v;
                v--;
                std::cout << (black_counts[union_find.leader(v)] > 0 ? "Yes" : "No") << '\n';
                break;
            }
            default: std::runtime_error("Invalid Input");
        }
    }
    std::cout << std::flush;
    return 0;
}