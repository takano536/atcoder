#include <iostream>
#include <vector>

int main() {
    long long n;
    std::cin >> n;

    int a = 1;
    long long ans = 0;
    while (true) {
        __uint128_t ok = 0;
        __uint128_t ng = 1e9;
        while (ng - ok > 1) {
            __uint128_t mid = (ok + ng) / 2;
            __uint128_t x = mid * mid * (1LL << a);
            (x > n) ? ng = mid : ok = mid;
        }
        ans += (ok + (2 - 1)) / 2;
        if (ok == 0) break;
        a++;
    }

    std::cout << ans << std::endl;
    return 0;
}