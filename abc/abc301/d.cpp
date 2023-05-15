#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    long long n;
    std::cin >> n;

    long long ans = 0;
    int s_len = s.size();
    std::string reversed_s = s;
    std::reverse(reversed_s.begin(), reversed_s.end());
    for (int i = 0; i < s_len; i++) {
        if (reversed_s[i] == '1') {
            ans += std::pow(2.0L, i);
        }
    }

    if (ans > n) {
        std::cout << -1 << std::endl;
        return 0;
    }

    for (int i = 0; i < s_len; i++) {
        if (s[i] == '?' && ans + std::pow(2.0L, s_len - i - 1) <= n) {
            ans += std::pow(2.0L, s_len - i - 1);
        }
    }

    std::cout << ans << std::endl;
    return 0;
}