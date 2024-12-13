#include <array>
#include <iostream>
#include <vector>

int main() {
    constexpr std::array<int, 6> PRICES = {
        100, 101, 102, 103, 104, 105
    };

    int x;
    std::cin >> x;

    std::vector<bool> exists(x + 1);
    exists[0] = true;

    for (int i = 0; i < x; i++) {
        if (!exists[i]) continue;
        for (const auto &price : PRICES) {
            if (i + price > x) continue;
            exists[i + price] = true;
        }
    }

    std::cout << exists[x] << std::endl;
    return 0;
}