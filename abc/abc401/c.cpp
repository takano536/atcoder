#include <iostream>
#include <vector>

#include <atcoder/lazysegtree>

constexpr long long MOD = 1e9;

struct S {
    long long value;
    int size;
};
using F = long long;

S op(S a, S b) { return {(a.value + b.value) % MOD, a.size + b.size}; }
S e() { return {0, 0}; }
S mapping(F f, S x) { return {x.value + f * x.size, x.size}; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

int main() {
    int n, k;
    std::cin >> n >> k;

    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(n + 1);
    for (int i = 0; i <= n; i++) {
        if (i < k) {
            seg.set(i, {1, 1});
        } else {
            seg.set(i, {seg.prod(i - k, i).value, 1});
        }
    }

    std::cout << seg.get(n).value << std::endl;
    return 0;
}