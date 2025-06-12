#include <cmath>
#include <iostream>

int main() {
    long long n;
    std::cin >> n;

    const __uint128_t d_max = std::cbrt(n) + 1;
    for (__uint128_t d = 0; d <= d_max; d++) {
        __uint128_t ok = 1;
        __uint128_t ng = n;
        while (ng - ok > 1) {
            const auto mid = (ok + ng) / 2;
            const auto x = d + mid;
            const auto y = mid;
            (x * x * x - y * y * y <= static_cast<__uint128_t>(n) ? ok : ng) = mid;
        }
        const long long x = d + ok;
        const long long y = ok;
        if (x * x * x - y * y * y != n) continue;
        std::cout << x << ' ' << y << std::endl;
        return 0;
    }

    std::cout << -1 << std::endl;
    return 0;
}