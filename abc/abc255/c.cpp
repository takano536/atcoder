#include <iostream>

int main() {
    long long x, a, d, n;
    std::cin >> x >> a >> d >> n;

    if (d < 0) {
        a += (n - 1) * d;
        d *= -1;
    }

    long long ok = 1;
    long long ng = n;
    while (std::abs(ok - ng) > 1) {
        long long mid = (ok + ng) / 2;
        (a + (mid - 1) * d <= x ? ok : ng) = mid;
    }

    long long ans = 8e18;
    for (long long i = std::max(ok - 5, 1LL); i <= std::min(ok + 5, n); i++) {
        ans = std::min(ans, std::abs(x - (a + (i - 1) * d)));
    }
    std::cout << ans << std::endl;
    return 0;
}