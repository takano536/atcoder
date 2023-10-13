#include <iostream>
#include <vector>

#include <atcoder/lazysegtree>

// https://betrue12.hateblo.jp/entry/2020/09/23/005940
using S = long;
using F = long;

const S INF = 8e18;
const F ID = 8e18;

S op(S a, S b){ return std::max(a, b); }
S e(){ return 0; }
S mapping(F f, S x){ return (f == ID ? x : f); }
F composition(F f, F g){ return (f == ID ? g : f); }
F id(){ return ID; }

int main() {
    int w, n;
    std::cin >> w >> n;

    std::vector<S> v(w);
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> ruq(v);

    for (int i = 0;i < n; i++) {
        int l, r;
        std::cin >> l >> r;
        l--, r--;

        ruq.apply(l, r + 1, ruq.prod(l, r + 1) + 1);
        std::cout << ruq.prod(l, r + 1) << std::endl;
    }
    return 0;
}