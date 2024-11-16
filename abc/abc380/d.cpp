#include <bitset>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s;
    std::cin >> s;

    const int n = s.size();

    int q;
    std::cin >> q;

    std::vector<long long> k(q);
    for (auto &ki : k) std::cin >> ki;

    for (const auto &ki : k) {
        long long group = (ki + n - 1) / n - 1;
        bool is_swapped = std::bitset<64>(group).count() % 2;
        int idx = (ki - 1) % n;
        if (is_swapped) {
            std::cout << static_cast<char>(std::isupper(s[idx]) ? std::tolower(s[idx]) : std::toupper(s[idx])) << ' ';
        } else {
            std::cout << s[idx] << ' ';
        }
    }
    std::cout << std::endl;
    return 0;
}