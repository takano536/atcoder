#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    std::ranges::sort(a);
    std::ranges::sort(b);

    std::vector<int> dists;
    std::ranges::transform(a, b, std::back_inserter(dists), [](int a, int b) { return std::abs(a - b); });

    std::cout << std::accumulate(dists.begin(), dists.end(), 0LL) << std::endl;
    return 0;
}