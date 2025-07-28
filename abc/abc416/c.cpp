#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, k, x;
    std::cin >> n >> k >> x;

    std::vector<std::string> s(n);
    for (auto &si : s) std::cin >> si;

    std::vector<std::string> words;
    auto dfs = [&](auto &&self, const std::string &word, const int count) -> void {
        if (count >= k) {
            words.push_back(word);
            return;
        }

        for (int i = 0; i < n; i++) {
            const auto next_word = word + s[i];
            self(self, next_word, count + 1);
        }
        return;
    };

    dfs(dfs, "", 0);
    std::ranges::sort(words);

    std::cout << words[x - 1] << std::endl;
    return 0;
}