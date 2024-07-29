#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    std::ranges::sort(a);

    while (q--) {
        int b, k;
        std::cin >> b >> k;

        long long ok = 1e18;
        long long ng = -1;
        while (ok - ng > 1) {
            long long mid = (ok + ng) / 2;

            long long l = -mid + b;
            long long r = +mid + b;
            auto l_iter = std::ranges::lower_bound(a, l);
            auto r_iter = std::ranges::upper_bound(a, r);
            int l_idx = std::distance(a.begin(), l_iter);
            int r_idx = std::distance(a.begin(), r_iter) - 1;
            int cnt = l_iter == a.end() || r_iter == a.begin() ? 0 : r_idx - l_idx + 1;

            (cnt >= k ? ok : ng) = mid;
        }

        std::cout << ok << std::endl;
    }
    return 0;
}