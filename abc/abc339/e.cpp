#include <iostream>
#include <vector>

#include <atcoder/segtree>

int op(int a, int b) {
    return std::max(a, b);
}

int e() {
    return 0;
}

int main() {
    const int MAX_A = 5 * 1e5;

    int n, d;
    std::cin >> n >> d;

    std::vector<int> a(n);
    for (auto &ai : a) {
        std::cin >> ai;
    }

    atcoder::segtree<int, op, e> dp(MAX_A + 1);
    dp.set(a[0], 1);
    for (int i = 1; i < n; i++) {
        int left = std::max(1, a[i] - d);
        int right = std::min(MAX_A, a[i] + d) + 1;
        dp.set(a[i], dp.prod(left, right) + 1);
    }

    std::cout << dp.all_prod() << std::endl;
    return 0;
}