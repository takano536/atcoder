#include <iostream>
#include <vector>

int main() {
    constexpr int MAX_A = 1e6;

    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    std::vector<int> a_cnts(MAX_A + 1);
    std::vector<bool> exists(MAX_A + 1);
    for (auto &ai : a) std::cin >> ai, exists[ai] = true, a_cnts[ai]++;

    std::vector<int> divisors_cnts(MAX_A + 1);
    std::vector<int> ans(MAX_A + 1, 1);
    for (int i = 2; i <= MAX_A; i++) {
        for (int j = i; j <= MAX_A; j += i) {
            if (exists[j]) divisors_cnts[i] += a_cnts[j];
        }
        for (int j = i; j <= MAX_A; j += i) {
            if (exists[j] && divisors_cnts[i] >= k) ans[j] = i;
        }
    }

    std::vector<int> primes;
    for (const auto &ai : a) std::cout << ans[ai] << std::endl;

    return 0;
}