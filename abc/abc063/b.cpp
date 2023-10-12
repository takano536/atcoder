#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    std::ranges::sort(s);

    for (std::size_t i = 0; i < s.length() - 1; i++) {
        if (s[i] == s[i + 1]) {
            std::cout << "no" << std::endl;
            return 0;
        }
    }
    std::cout << "yes" << std::endl;

    return 0;
}