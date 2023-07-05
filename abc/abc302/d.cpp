#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, m;
    long long d;
    std::cin >> n >> m >> d;

    std::vector<long long> a(n), b(m);
    for (auto &A : a) {
        std::cin >> A;
    }
    for (auto &B : b) {
        std::cin >> B;
    }

    std::sort(b.begin(), b.end());

    long long ans = -1;
    for (auto &value : a) {
        const auto left = value - d;
        const auto right = value + d;

        auto b_iter = std::upper_bound(b.begin(), b.end(), value + d);
        b_iter--;

        if (*b_iter < left || *b_iter > right) {
            continue;
        }
        ans = std::max(value + *b_iter, ans);
    }

    std::cout << ans << std::endl;
    return 0;
}