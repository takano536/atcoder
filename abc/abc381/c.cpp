#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
    int n;
    std::cin >> n;

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
    if (encoded_s.size() < 3) {
        std::cout << 1 << std::endl;
        return 0;
    }

    int ans = 1;
    for (auto iter = std::next(encoded_s.begin()); iter != std::prev(encoded_s.end()); iter++) {
        if (iter->first != '/') continue;
        if (iter->second != 1) continue;
        if (std::prev(iter)->first == '1' && std::next(iter)->first == '2') {
            ans = std::max(1 + std::min(std::prev(iter)->second, std::next(iter)->second) * 2, ans);
        }
    }

    std::cout << ans << std::endl;
    return 0;
}