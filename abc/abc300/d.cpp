#include <cmath>
#include <iostream>
#include <vector>

std::vector<unsigned long long> eratosthenes(const int n) {
    std::vector<bool> is_prime(n + 1);
    for (int i = 0; i <= n; i++) {
        is_prime[i] = true;
    }

    std::vector<unsigned long long> primes;
    for (int i = 2; i <= n; i++) {
        if (!is_prime[i]) {
            continue;
        }

        for (int j = 2 * i; j <= n; j += i) {
            is_prime[j] = false;
        }
        primes.emplace_back(i);
    }

    return primes;
}

int main() {
    unsigned long long n;
    std::cin >> n;

    auto primes = eratosthenes(std::sqrt(static_cast<double>(n) / 2 / 2 / 3));
    int primes_size = primes.size();

    int ans = 0;
    for (int i = 0; i < primes_size; i++) {
        for (int j = i + 1; j < primes_size; j++) {
            for (int k = j + 1; k < primes_size; k++) {
                if (primes[i] * primes[i] * primes[j] > n) {
                    break;
                }
                if (primes[i] * primes[i] * primes[j] * primes[k] > n) {
                    break;
                }
                if (primes[i] * primes[i] * primes[j] * primes[k] * primes[k] > n) {
                    break;
                }
                ans++;
            }
        }
    }
    std::cout << ans << std::endl;
}