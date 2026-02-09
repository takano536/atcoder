#include <iostream>
#include <vector>

#include <atcoder/segtree>

const int INF = 1 << 30;

int max_op(int a, int b) { return std::max(a, b); }
int min_op(int a, int b) { return std::min(a, b); }
int max_e() { return -INF; }
int min_e() { return +INF; }

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> h(n);
    for (auto &hi : h) std::cin >> hi;

    atcoder::segtree<int, max_op, max_e> max_rmq(h);
    atcoder::segtree<int, min_op, min_e> min_rmq(h);

    long long ans = 0;
    for (int i = 0; i <= n - k; i++) {
        ans = std::max(static_cast<long long>(max_rmq.prod(i, i + k)) - min_rmq.prod(i, i + k), ans);
    }

    std::cout << ans << std::endl;
    return 0;
}