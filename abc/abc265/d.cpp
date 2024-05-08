#include <iostream>
#include <set>
#include <vector>

int main() {
    int n;
    long long p, q, r;
    std::cin >> n >> p >> q >> r;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    std::set<long long> cumsum;
    cumsum.insert(0);
    for (auto &ai : a) cumsum.insert(*cumsum.rbegin() + ai);

    bool is_satisfied = false;
    for (auto cumsum_iter = cumsum.begin(); cumsum_iter != cumsum.end(); cumsum_iter++) {
        auto y_iter = cumsum.lower_bound(p + *cumsum_iter);
        if (*y_iter - *cumsum_iter != p) {
            continue;
        }
        auto z_iter = cumsum.lower_bound(q + *y_iter);
        if (*z_iter - *y_iter != q) {
            continue;
        }
        auto w_iter = cumsum.lower_bound(r + *z_iter);
        if (*w_iter - *z_iter != r) {
            continue;
        }
        is_satisfied = true;
        break;
    }

    std::cout << (is_satisfied ? "Yes" : "No") << std::endl;
    return 0;
}