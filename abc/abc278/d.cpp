#include <iostream>
#include <vector>

#include <atcoder/lazysegtree>

using S = long long;
using F = long long;

const S INF = 8e18;
const F ID = 8e18;

S op(S a, S b) { return std::min(a, b); }
S e() { return INF; }
S mapping(F f, S x) { return (f == ID ? x : f); }
F composition(F f, F g) { return (f == ID ? g : f); }
F id() { return ID; }

int main() {
    int n;
    std::cin >> n;

    std::vector<S> a(n);
    for (auto &ai : a) std::cin >> ai;

    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);

    int q;
    std::cin >> q;

    while (q--) {
        int opt;
        std::cin >> opt;

        switch (opt) {
            case 1: {
                int x;
                std::cin >> x;
                seg.apply(0, n, x);
                break;
            }
            case 2: {
                int i, x;
                std::cin >> i >> x;
                i--;
                seg.apply(i, seg.get(i) + x);
                break;
            }
            case 3: {
                int i;
                std::cin >> i;
                i--;
                std::cout << seg.get(i) << std::endl;
                break;
            }
            default:
                exit(-1);
        }
    }
}