#include <iostream>

#include <atcoder/fenwicktree>

int main() {
    int n, q;
    std::cin >> n >> q;
    atcoder::fenwick_tree<long long> fenwick(n);
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        fenwick.add(i, a);
    }

    while (q--) {
        int query;
        std::cin >> query;

        switch (query) {
            case 1: {
                int x;
                std::cin >> x;
                x--;
                const int curr_val = fenwick.sum(x, x + 1);
                const int next_val = fenwick.sum(x + 1, x + 2);
                fenwick.add(x, -curr_val);
                fenwick.add(x + 1, -next_val);
                fenwick.add(x, next_val);
                fenwick.add(x + 1, curr_val);
                break;
            }
            case 2: {
                int l, r;
                std::cin >> l >> r;
                l--, r--;
                std::cout << fenwick.sum(l, r + 1) << '\n';
                break;
            }
        }
    }
    std::cout << std::flush;
    return 0;
}