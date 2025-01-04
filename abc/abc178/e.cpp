#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> z(n), w(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        z[i] = x + y;
        w[i] = x - y;
    }

    long long z_max = std::abs(*std::ranges::max_element(z) - *std::ranges::min_element(z));
    long long w_max = std::abs(*std::ranges::max_element(w) - *std::ranges::min_element(w));
    std::cout << std::max(z_max, w_max) << std::endl;
    return 0;
}