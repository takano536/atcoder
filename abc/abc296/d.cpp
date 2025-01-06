#include <cmath>
#include <iostream>
#include <limits>

int main() {
    constexpr long long INF = std::numeric_limits<long long>::max();

    long long n, m;
    std::cin >> n >> m;

    long long ans = INF;
    for (int a = 1; a <= std::sqrt(m) + 1; a++) {
        long long b = (m + a - 1) / a;
        if (a <= n && b <= n) ans = std::min(a * b, ans);
    }

    std::cout << (ans != INF ? ans : -1) << std::endl;
    return 0;
}