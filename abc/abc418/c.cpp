#include <algorithm>
#include <iostream>
#include <vector>

void solve(const std::vector<int> &a, const std::vector<long long> &cumsum) {
    int b;
    std::cin >> b;

    const auto iter = std::ranges::upper_bound(a, b - 1) - 1;
    const auto index = std::distance(a.begin(), iter);
    const long long ans = cumsum[index + 1] + (b - 1) * (a.size() - (index + 1)) + 1;

    std::cout << (ans > cumsum.back() ? -1 : ans) << '\n';
}

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    std::ranges::sort(a);
    std::vector<long long> cumsum(n + 1);
    for (int i = 0; i < n; i++) cumsum[i + 1] = cumsum[i] + a[i];

    while (q--) solve(a, cumsum);
    std::cout << std::flush;
    return 0;
}