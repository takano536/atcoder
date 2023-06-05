#include <iostream>
#include <set>
#include <vector>

int main() {
    const int MOD = 1 << 20;

    int q;
    std::cin >> q;

    std::set<int> free_idxs;
    for (int i = 0; i < MOD; i++) {
        free_idxs.insert(i);
    }

    std::vector<long long> a(MOD, -1);

    for (int i = 0; i < q; i++) {
        int t;
        long long x;
        std::cin >> t >> x;

        switch (t) {
            case 1: {
                auto insert_idx_iter = free_idxs.lower_bound(x % MOD);
                if (insert_idx_iter == free_idxs.end()) {
                    insert_idx_iter = free_idxs.begin();
                }
                a[*insert_idx_iter] = x;
                free_idxs.erase(insert_idx_iter);
                break;
            }
            case 2: {
                std::cout << a[x % MOD] << std::endl;
                break;
            }
            default: {
                abort();
            }
        }
    }
    return 0;
}