#include <iostream>
#include <map>
#include <vector>

std::map<long long, long long> prime_factorize(long long n) {
    std::map<long long, long long> res;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i != 0) continue;
        long long cnt = 0;
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
        res[i] = cnt;
    }
    if (n != 1) res[n] = 1;
    return res;
}

long long count_divisible_num(long long n, long long p) {
    if (n == 0) return 0;
    n /= p;
    return n + count_divisible_num(n, p);
}

int main() {
    long long k;
    std::cin >> k;

    auto primes = prime_factorize(k);

    long long ng = 1;
    long long ok = k;
    while (ok - ng > 1) {
        auto mid = (ok + ng) / 2;

        bool is_satisfied = true;
        for (const auto &[prime, cnt] : primes) {
            if (count_divisible_num(mid, prime) < cnt) {
                is_satisfied = false;
                break;
            }
        }

        (is_satisfied ? ok : ng) = mid;
    }

    std::cout << ok << std::endl;
    return 0;
}