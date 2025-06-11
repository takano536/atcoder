#include <algorithm>
#include <iostream>
#include <vector>

#include <atcoder/modint>

int main() {
    int n;
    std::cin >> n;

    atcoder::modint::set_mod(n);

    std::vector<int> p(n);
    for (auto &pi : p) std::cin >> pi;

    std::vector<int> counts(n);
    for (int i = 0; i < n; i++) {
        for (int j = -1; j <= 1; j++) {
            atcoder::modint index = p[i] - i + j;
            counts[index.val()]++;
        }
    }

    std::cout << *std::ranges::max_element(counts) << std::endl;
    return 0;
}