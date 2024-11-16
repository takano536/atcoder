#include <bitset>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s;
    std::cin >> s;

    std::string flipped_s = s;
    for (auto &c : flipped_s) c = (std::isupper(c) ? std::tolower(c) : std::toupper(c));

    const int n = s.size();

    int q;
    std::cin >> q;

    std::vector<long long> k(q);
    for (auto &ki : k) std::cin >> ki;

    for (const auto &ki : k) {
        long long group = (ki + n - 1) / n - 1;
        bool is_flipped = std::bitset<64>(group).count() % 2;
        int idx = (ki - 1) % n;
        std::cout << (is_flipped ? flipped_s[idx] : s[idx]) << ' ';
    }
    std::cout << std::endl;
    return 0;
}