#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(m);
    for (int i = 0; i < m; i++) {
        std::cin >> a[i];
        a[i]--;
    }

    for (int i = 0; i < n; i++) {
        auto day_iter = std::ranges::lower_bound(a, i);
        std::cout << *day_iter - i << std::endl;
    }
    return 0;
}