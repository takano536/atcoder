#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> k(n);
    for (auto &ki : k) std::cin >> ki;

    long long ans = 1e18;
    for (int i = 0; i < (1 << n); ++i) {
        long long a = 0, b = 0;
        for (int j = 0; j < n; ++j) (i & (1 << j) ? a : b) += k[j];
        ans = std::min(ans, std::max(a, b));
    }

    std::cout << ans << std::endl;
    return 0;
}