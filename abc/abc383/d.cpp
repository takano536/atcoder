#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main() {
    constexpr long long MAX_N = 4e12;

    long long n;
    std::cin >> n;

    const int N_SQRT = std::sqrt(n);
    const int N_OCRT = std::pow(n, 1.0 / 8);

    std::vector<int> is_prime(std::sqrt(MAX_N) + 1, true);
    for (int i = 2; i <= std::sqrt(MAX_N); i++) {
        if (!is_prime[i]) continue;
        for (int j = i * 2; j <= std::sqrt(MAX_N); j += i) {
            is_prime[j] = false;
        }
    }

    std::vector<int> primes;
    for (int i = 2; i <= std::sqrt(MAX_N); i++) {
        if (is_prime[i]) primes.push_back(i);
    }

    int ans = 0;
    for (auto iter = primes.begin(); iter != primes.end(); iter++) {
        auto it = std::ranges::upper_bound(primes, N_SQRT / *iter);
        if (it == primes.begin()) continue;
        it--;
        ans += std::max<int>(0, std::distance(iter, it));
        if (*iter <= N_OCRT) ans++;
    }

    std::cout << ans << std::endl;
    return 0;
}