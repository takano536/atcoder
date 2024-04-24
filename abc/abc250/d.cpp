#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main() {
    long long n;
    std::cin >> n;

    const int N_CUEB_ROOT = std::pow(n, 1.0 / 3);

    std::vector<bool> is_prime(N_CUEB_ROOT + 1, true);
    for (int i = 2; i <= N_CUEB_ROOT; i++) {
        if (!is_prime[i]) {
            continue;
        }
        for (int j = i * 2; j <= N_CUEB_ROOT; j += i) {
            is_prime[j] = false;
        }
    }

    std::vector<int> primes;
    for (int i = 2; i <= N_CUEB_ROOT; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    if (primes.size() < 2) {
        std::cout << 0 << std::endl;
        return 0;
    }

    long long ans = 0;
    for (const auto &q : std::vector<int>(primes.begin() + 1, primes.end())) {
        auto boundary = std::min<long long>(q - 1, n / q / q / q);
        auto iter = std::ranges::upper_bound(primes, boundary);
        if (iter == primes.begin()) {
            continue;
        }
        ans += std::ranges::distance(primes.begin(), std::prev(iter)) + 1;
    }

    std::cout << ans << std::endl;
    return 0;
}