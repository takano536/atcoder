#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (auto &ai : a) {
        std::cin >> ai;
    }
    std::ranges::sort(a);

    std::vector<long long> cumsum(n + 1);
    for (int i = 0; i < n; i++) {
        cumsum[i + 1] = cumsum[i] + a[i];
    }

    while (q-- > 0) {
        int x;
        std::cin >> x;

        auto iter = std::ranges::upper_bound(a, x);
        auto border = std::ranges::distance(a.begin(), iter);
        long long left_n = border;
        long long right_n = n - left_n;

        long long ans = 0;
        ans += std::abs(cumsum[border] - left_n * x);
        ans += std::abs((cumsum[n] - cumsum[border]) - right_n * x);

        std::cout << ans << std::endl;
    }
    return 0;
}