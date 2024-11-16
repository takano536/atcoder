#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    auto rle = [](const std::string &s) {
        std::vector<std::pair<char, int>> res;
        for (const char &c : s) {
            if (res.empty() || res.back().first != c) {
                res.emplace_back(c, 1);
                continue;
            }
            res.back().second++;
        }
        return res;
    };

    auto encoded_s = rle(s);
    int chunk_idx = 0;
    for (std::size_t i = 0; i < encoded_s.size(); i++) {
        const auto &[c, _] = encoded_s[i];
        if (c == '1') chunk_idx++;
        if (chunk_idx == k) std::swap(encoded_s[i - 1], encoded_s[i]);
    }

    for (const auto &[c, num] : encoded_s) std::cout << std::string(num, c);
    std::cout << std::endl;

    return 0;
}