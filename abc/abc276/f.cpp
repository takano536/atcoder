#include <iostream>
#include <vector>

#include <atcoder/fenwicktree>
#include <atcoder/modint>

int main() {
    constexpr int A_MAX = 2e5;
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    atcoder::fenwick_tree<long long> dist(A_MAX + 1), sums(A_MAX + 1);

    atcoder::modint numer;
    for (int k = 0; k < n; k++) {
        numer += dist.sum(0, a[k] + 1) * 2 * a[k];
        numer += sums.sum(a[k] + 1, A_MAX + 1) * 2;
        numer += a[k];
        const long long denom = static_cast<long long>(k + 1) * (k + 1);
        std::cout << (numer / denom).val() << std::endl;
        dist.add(a[k], 1);
        sums.add(a[k], a[k]);
    }
    return 0;
}