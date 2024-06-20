#include <cmath>
#include <iostream>

bool is_prime(long long n) {
    if (n == 1) return false;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        long long n;
        std::cin >> n;

        long long p = 0, q = 0;
        for (long long i = 2; i < std::pow(n, 1.0 / 3) + 1; i++) {
            if (n % (i * i) == 0) {
                p = i;
                break;
            }
            if (n % i == 0) {
                q = i;
                break;
            }
        }
        if (p == 0) p = std::round(std::sqrt(static_cast<long double>(n) / q));
        if (q == 0) q = n / p / p;

        std::cout << p << ' ' << q << std::endl;
    }

    return 0;
}