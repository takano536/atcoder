#include <algorithm>
#include <cmath>
#include <iostream>
#include <ranges>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;
    std::ranges::sort(s);

    int ans = 0;
    for (long i = 0; i * i < static_cast<long>(std::pow(10, n)); i++) {
        auto num = std::to_string(i * i);
        num = std::string(std::max(n - num.size(), 0UL), '0') + num;
        std::ranges::sort(num);
        if (s == num) {
            ans++;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}