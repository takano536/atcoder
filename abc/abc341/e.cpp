#include <iostream>
#include <string>
#include <vector>

#include <atcoder/segtree>

bool op(bool a, bool b) {
    return a || b;
}

bool e() {
    return false;
}

int main() {
    int n, q;
    std::cin >> n >> q;

    std::string s;
    std::cin >> s;

    std::vector<bool> vec(n - 1);
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            vec[i] = true;
        }
    }
    atcoder::segtree<bool, op, e> is_bad(vec);

    for (int i = 0; i < q; i++) {
        int query, l, r;
        std::cin >> query >> l >> r;
        l--, r--;

        switch (query) {
            case 1: {
                if (n == 1) {
                    break;
                }
                if (l > 0) {
                    is_bad.set(l - 1, !is_bad.get(l - 1));
                }
                if (r < n - 1) {
                    is_bad.set(r, !is_bad.get(r));
                }
                break;
            }
            case 2: {
                if (n == 1) {
                    std::cout << "Yes" << std::endl;
                } else {
                    std::cout << (is_bad.prod(l, r) ? "No" : "Yes") << std::endl;
                }
                break;
            }
            default: {
                return -1;
            }
        }
    }
    return 0;
}