#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <atcoder/modint>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    std::vector dp(n, std::vector<atcoder::modint>(1 << k));
    if (s[0] == 'A' || s[0] == '?') dp[0][0] = 1;
    if (s[0] == 'B' || s[0] == '?') dp[0][1] = 1;

    auto bin2str = [&k](const int bin) {
        std::string ret;
        for (int i = 0; i < k; i++) ret += ((bin & (1 << i)) ? 'B' : 'A');
        return ret;
    };

    auto is_palindrome = [&k](const std::string &s) {
        for (int i = 0; i < k / 2; i++) {
            if (s[i] != s[k - 1 - i]) return false;
        }
        return true;
    };

    for (int i = 1; i < n; i++) {
        for (int prev_bit = 0; prev_bit < (1 << k); prev_bit++) {
            if (dp[i - 1][prev_bit].val() == 0) continue;

            for (const auto &c : {'A', 'B'}) {

                if (s[i] != '?' && s[i] != c) continue;

                const int next_bit = ((prev_bit << 1) & ((1 << k) - 1)) | (c == 'B');
                std::string substr = bin2str(next_bit);
                if (i >= k - 1 && is_palindrome(substr)) continue;

                dp[i][next_bit] += dp[i - 1][prev_bit];
            }
        }
    }

    atcoder::modint ans;
    for (int bit = 0; bit < (1 << k); bit++) ans += dp[n - 1][bit];
    std::cout << ans.val() << std::endl;
    return 0;
}