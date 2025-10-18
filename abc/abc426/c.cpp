#include <iostream>
#include <vector>

#include <atcoder/lazysegtree>

struct S {
    int value;
    int size;
};
using F = int;

const F ID = 1e9;

S op(S a, S b) { return {a.value + b.value, a.size + b.size}; }
S e() { return {0, 0}; }
S mapping(F f, S x) {
    if (f != ID) x.value = f * x.size;
    return x;
}
F composition(F f, F g) { return (f == ID ? g : f); }
F id() { return ID; }

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<S> v(n, {1, 1});
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

    while (q--) {
        int x, y;
        std::cin >> x >> y;
        int ans = seg.prod(0, x).value;
        std::cout << ans << std::endl;
        seg.apply(0, x, 0);

        auto elem = seg.get(y - 1);
        elem.value += ans;
        seg.set(y - 1, elem);
    }
}