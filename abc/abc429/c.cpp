#include <iostream>
#include <map>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::map<int, int> counts;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        counts[a]++;
    }

    long long ans = 0;
    for (auto &[ai, count] : counts) {
        const auto nCr = static_cast<long long>(count) * (count - 1) / 2;
        ans += nCr * (n - count);
    }

    std::cout << ans << std::endl;
    return 0;
}