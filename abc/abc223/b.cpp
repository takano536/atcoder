#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s;
    std::cin >> s;
    int s_len = s.size();

    std::vector<std::string> words;
    auto curr = s;
    for (int i = 0; i < s_len; i++) {
        words.push_back(curr);
        auto head = curr[0];
        for (auto iter = curr.begin(); iter != curr.end(); iter++) {
            *iter = *std::next(iter);
        }
        curr.back() = head;
    }

    std::ranges::sort(words);
    // clang-format off
    std::cout << words[0] << std::endl << words.back() << std::endl;  // clang-format on
    return 0;
}