#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
    constexpr int NA = -1;

    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n - 1);
    for (auto &ai : a) std::cin >> ai;
    for (auto &bi : b) std::cin >> bi;

    std::ranges::sort(a);
    std::ranges::sort(b);

    int ans = NA;
    for (int i = n - 1; i >= 0; i--) {
        if (b.back() >= a[i]) {
            b.pop_back();
        } else {
            if (ans != NA) {
                std::cout << -1 << std::endl;
                return 0;
            }
            ans = a[i];
        }
    }

    std::cout << ans << std::endl;
    return 0;
}