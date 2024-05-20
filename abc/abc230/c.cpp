#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
    long long n, a, b, p, q, r, s;
    std::cin >> n >> a >> b >> p >> q >> r >> s;

    std::vector ans(q - p + 1, std::string(s - r + 1, '.'));

    std::pair<long long, long long> k_min = {std::max(1 - a, 1 - b), std::max(1 - a, b - n)};
    std::pair<long long, long long> k_max = {std::min(n - a, n - b), std::min(n - a, b - 1)};
    for (long long i = p; i <= q; i++) {
        for (long long j = r; j <= s; j++) {
            if (i - a == j - b && k_min.first <= i - a && i - a <= k_max.first && k_min.first <= j - b && j - b <= k_max.first) {
                ans[i - p][j - r] = '#';
            }
            if (i - a == b - j && k_min.second <= i - a && i - a <= k_max.second && k_min.second <= b - j && b - j <= k_max.second) {
                ans[i - p][j - r] = '#';
            }
        }
    }

    for (const auto &si : ans) std::cout << si << std::endl;
    return 0;
}