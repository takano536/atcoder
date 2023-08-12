#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }

    auto max_iter = std::max_element(p.begin(), p.end());
    if (max_iter == p.begin() && std::count(p.begin(), p.end(), *max_iter) == 1) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << *max_iter - p[0] + 1 << std::endl;
    }
    return 0;
}