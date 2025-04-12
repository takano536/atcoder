#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    int o_count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'o') o_count++;
        if (s[i] != '?') continue;
        if (i > 0 && s[i - 1] == 'o') s[i] = '.';
        if (i < n - 1 && s[i + 1] == 'o') s[i] = '.';
    }

    const int shortage = k - o_count;

    if (shortage == 0) {
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') s[i] = '.';
        }
        std::cout << s << std::endl;
        return 0;
    }

    auto rle = [](const std::string &s) {
        std::vector<std::pair<char, int>> res;
        for (const auto &c : s) {
            if (res.empty() || res.back().first != c) {
                res.emplace_back(c, 1);
                continue;
            }
            res.back().second++;
        }
        return res;
    };

    int max_count = 0;
    const auto encoded_s = rle(s);
    for (const auto &[chr, len] : encoded_s) {
        if (chr != '?') continue;
        max_count += (len + (2 - 1)) / 2;
    }

    if (max_count != shortage) {
        std::cout << s << std::endl;
        return 0;
    }

    int index = 0;
    for (const auto &[chr, len] : encoded_s) {
        const int prev_index = index;
        index += len;
        if (chr != '?') continue;
        if (len % 2 == 0) continue;
        for (int i = prev_index, j = 0; i < index; i++, j++) {
            s[i] = (j % 2 == 0 ? 'o' : '.');
        }
    }

    std::cout << s << std::endl;
    return 0;
}