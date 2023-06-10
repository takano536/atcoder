#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &ai : a) {
        std::cin >> ai;
    }

    std::vector<long long> cumsum(n + 1);
    for (int i = 3; i <= n; i++) {
        if ((i - 1) % 2) {
            cumsum[i] = 0;
        } else {
            cumsum[i] = cumsum[i - 2] + (a[i - 1] - a[i - 2]);
        }
    }

    int q;
    std::cin >> q;
    std::vector<long long> anss(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;

        auto l_iter = std::lower_bound(a.begin(), a.end(), l);
        auto r_iter = std::lower_bound(a.begin(), a.end(), r);

        if (*l_iter != l) {
            l_iter--;
        }

        int cumsum_l = (l_iter - a.begin() + 1) % 2 ? l_iter - a.begin() + 1 : l_iter - a.begin() + 1 - 1;
        int cumsum_r = (r_iter - a.begin() + 1) % 2 ? r_iter - a.begin() + 1 : r_iter - a.begin() + 1 - 1;
        long long ans = cumsum[cumsum_r] - cumsum[cumsum_l];

        if (*l_iter != l && (l_iter - a.begin()) % 2) {
            ans -= l - *l_iter;
        }
        if (*r_iter != r && (r_iter - a.begin()) % 2 == 0) {
            ans += r - *r_iter;
        }

        anss[i] = ans;
    }

    for (auto ans : anss) {
        std::cout << ans << std::endl;
    }
    return 0;
}