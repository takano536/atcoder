#include <iostream>
#include <set>
#include <vector>

#include <atcoder/dsu>

int main() {
    constexpr int MAX_K = 10;

    int n, q;
    std::cin >> n >> q;

    atcoder::dsu dsu(n);
    std::vector<std::set<int, std::greater<int>>> nums(n);
    for (int i = 0; i < n; i++) nums[i].insert(i);

    while (q--) {
        int opt;
        std::cin >> opt;
        switch (opt) {
            case 1: {
                int u, v;
                std::cin >> u >> v;
                u--, v--;
                auto u_leader = dsu.leader(u);
                auto v_leader = dsu.leader(v);
                dsu.merge(u, v);
                for (const auto &x : nums[u_leader]) nums[dsu.leader(u)].insert(x);
                for (const auto &x : nums[v_leader]) nums[dsu.leader(u)].insert(x);
                while (nums[dsu.leader(u)].size() > MAX_K) {
                    nums[dsu.leader(u)].erase(std::prev(nums[dsu.leader(u)].end()));
                }
                break;
            }
            case 2: {
                int v, k;
                std::cin >> v >> k;
                v--;
                if (nums[dsu.leader(v)].size() < static_cast<std::size_t>(k)) {
                    std::cout << -1 << std::endl;
                } else {
                    std::cout << (*std::next(nums[dsu.leader(v)].begin(), k - 1)) + 1 << std::endl;
                }
                break;
            }
        }
    }
    return 0;
}