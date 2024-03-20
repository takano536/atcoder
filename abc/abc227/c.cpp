#include <cmath>
#include <iostream>

int main() {
    long long n;
    std::cin >> n;

    long long ans = 0;
    for (long long a = 1; a <= std::ceil(std::cbrtl(n)); a++) {
        for (long long b = a; b <= std::ceil(std::sqrt(static_cast<long double>(n) / a)); b++) {
            long long max_c = n / a / b;
            ans += std::max(0LL, max_c - b + 1);
        }
    }

    std::cout << ans << std::endl;
    return 0;
}