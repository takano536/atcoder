#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1), c(n + m + 1);
    for (auto &ai : a) {
        std::cin >> ai;
    }
    for (auto &ci : c) {
        std::cin >> ci;
    }
    std::ranges::reverse(a);
    std::ranges::reverse(c);

    std::vector<int> b(m + 1);
    for (int i = 0; i < m + 1; i++) {
        b[i] = c[i] / a[0];
        for (int j = 1; j < n + 1; j++) {
            c[i + j] -= a[j] * b[i];
        }
    }

    std::ranges::reverse(b);
    for (int i = 0; i < m + 1; i++) {
        std::cout << b[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}