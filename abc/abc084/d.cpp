#include <iostream>
#include <utility>
#include <vector>

int main() {
    const int MAX_N = 1e5;
    int q;
    std::cin >> q;

    std::vector<std::pair<int, int>> queries(q);
    for (auto &[l, r] : queries) std::cin >> l >> r;

    std::vector<bool> is_prime(MAX_N + 1, true);
    is_prime[0] = false, is_prime[1] = false;
    for (int i = 2; i <= MAX_N; i++) {
        if (!is_prime[i]) continue;
        for (int j = i * 2; j <= MAX_N; j += i) is_prime[j] = false;
    }

    std::vector<bool> is_like_2017(MAX_N + 1);
    for (int i = 1; i <= MAX_N; i += 2) {
        if (is_prime[i] && is_prime[(i + 1) / 2]) is_like_2017[i] = true;
    }

    std::vector<int> cumsum(MAX_N + 1 + 1);
    for (int i = 0; i <= MAX_N; i++) cumsum[i + 1] = cumsum[i] + is_like_2017[i];

    for (const auto &[l, r] : queries) std::cout << cumsum[r + 1] - cumsum[l] << std::endl;

    return 0;
}