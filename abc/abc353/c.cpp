#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    const int MOD = 1e8;

    std::vector<int> a(n);
    for (auto &ai : a) {
        std::cin >> ai;
    }

    std::vector<int> sorted_a = a;
    std::ranges::sort(sorted_a);

    std::vector<long long> a_cumsum(n + 1);
    for (int i = 0; i < n; i++) {
        a_cumsum[i + 1] = a_cumsum[i] + a[i];
    }

    long long ans = 0;
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        auto dist = std::distance(sorted_a.begin(), std::ranges::lower_bound(sorted_a, MOD - a[i]));
        ans += a_cumsum[n] - a_cumsum[i + 1];
        ans += static_cast<long long>(a[i]) * (n - i - 1);
        cnt += n - dist;
        if (a[i] >= MOD - a[i]) cnt--;
    }
    cnt /= 2;
    ans -= cnt * MOD;
    std::cout << ans << std::endl;
    return 0;
}