#include <iostream>
#include <string>
#include <utility>
#include <vector>

std::vector<std::pair<char, int>> rle(const std::string &s) {
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

int main() {
    int n, k;
    std::string s;

    std::cin >> n >> k >> s;

    auto encorded_s = rle(s);

    int ans = 0, curr_len = 0;
    int order_count = 0;
    auto tail_iter = encorded_s.begin();
    for (const auto &[c, len] : encorded_s) {
        ans = std::max(curr_len, ans);
        curr_len += len;
        if (c == '1') continue;

        order_count++;
        if (order_count <= k) continue;

        while (tail_iter->first == '1') curr_len -= (tail_iter++)->second;
        curr_len -= (tail_iter++)->second;
    }

    ans = std::max(curr_len, ans);
    std::cout << ans << std::endl;
    return 0;
}