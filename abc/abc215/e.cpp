#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

#include <atcoder/modint>

int main() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    const int CHAR_NUM = *std::ranges::max_element(s) - 'A' + 1;
    std::vector<char> chars(CHAR_NUM);
    std::iota(chars.begin(), chars.end(), 'A');
    chars.push_back('?');
    auto char2int = [](char c) -> int { return c - 'A'; };

    std::vector dp(n, std::vector(1 << CHAR_NUM, std::map<char, atcoder::modint>()));
    dp[0][0]['?'] = 1;
    dp[0][1 << char2int(s[0])][s[0]] = 1;

    for (int i = 1; i < n; i++) {
        for (int bit = 0; bit < (1 << CHAR_NUM); bit++) {
            for (const auto &c : chars) {
                if (dp[i - 1][bit][c].val() == 0) {
                    continue;
                }

                dp[i][bit][c] += dp[i - 1][bit][c];

                if (c != '?' && c != s[i] && bit & (1 << char2int(s[i]))) {
                    continue;
                }
                dp[i][bit | (1 << char2int(s[i]))][s[i]] += dp[i - 1][bit][c];
            }
        }
    }

    atcoder::modint ans;
    for (const auto &mp : dp[n - 1]) {
        for (const auto &c : chars) {
            if (c != '?' && mp.contains(c)) {
                ans += mp.at(c);
            }
        }
    }

    std::cout << ans.val() << std::endl;
    return 0;
}