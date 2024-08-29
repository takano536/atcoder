#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    constexpr int NA = -1;

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;
    int a_max = *std::ranges::max_element(a);

    std::vector<int> min_factors(a_max + 1, NA);
    std::vector<bool> is_prime(a_max + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    min_factors[0] = 0;
    min_factors[1] = 1;
    for (int i = 2; i <= a_max; i++) {
        if (!is_prime[i]) continue;
        min_factors[i] = i;
        for (long long j = static_cast<long long>(i) * i; j <= a_max; j += i) {
            is_prime[j] = false;
            if (min_factors[j] == NA) min_factors[j] = i;
        }
    }

    auto count_factors = [&min_factors](int n) {
        int res = 0;
        while (n != 1) {
            n /= min_factors[n];
            res++;
        }
        return res;
    };

    int is_win_anna = 0;
    for (const auto &ai : a) is_win_anna ^= count_factors(ai);

    std::cout << (is_win_anna ? "Anna" : "Bruno") << std::endl;
    return 0;
}