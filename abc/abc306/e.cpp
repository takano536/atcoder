#include <iostream>
#include <set>
#include <vector>

int main() {
    int n, q;
    std::size_t k;
    std::cin >> n >> k >> q;

    std::multiset<int> uppers, lowers;
    long long ans = 0;

    auto add = [&](int x) {
        if (uppers.size() < k) {
            uppers.insert(x);
            ans += x;
        } else {
            lowers.insert(x);
        }

        if (lowers.empty()) {
            return;
        }

        auto lower_iter = lowers.end();
        lower_iter--;

        if (*lower_iter <= *uppers.begin()) {
            return;
        }

        int lower = *lower_iter;
        int upper = *uppers.begin();
        lowers.erase(lower_iter);
        uppers.erase(uppers.begin());
        lowers.insert(upper);
        uppers.insert(lower);
        ans += lower - upper;
    };

    auto erase = [&](int x) {
        if (uppers.count(x)) {
            uppers.erase(uppers.find(x));
            ans -= x;
        } else {
            lowers.erase(lowers.find(x));
        }
    };

    auto adjust = [&]() {
        if (lowers.empty()) {
            return;
        }

        auto lower_iter = lowers.end();
        lower_iter--;

        while (uppers.size() < k) {
            uppers.insert(*lower_iter);
            ans += *lower_iter;
            lowers.erase(lower_iter);
            lower_iter--;
        }
    };

    std::vector<int> a(n, -1);
    for (int i = 0; i < q; i++) {
        int x, y;
        std::cin >> x >> y;
        x--;

        if (a[x] != -1) {
            erase(a[x]);
        }
        a[x] = y;
        add(a[x]);
        adjust();

        std::cout << ans << std::endl;
    }

    return 0;
}