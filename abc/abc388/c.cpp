#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    long long ans = 0;
    for (const auto &ai : a) {
        const int threshold = ai * 2;
        const auto iter = std::ranges::lower_bound(a, threshold);
        ans += n - std::distance(a.begin(), iter);
    }

    std::cout << ans << std::endl;
    return 0;
}