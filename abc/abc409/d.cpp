#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::string s;
        std::cin >> n >> s;

        int l = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] <= s[i + 1]) continue;
            l = i;
            break;
        }

        auto tail_char = s[l];
        int r = n - 1;
        for (int i = l + 1; i < n; i++) {
            if (tail_char >= s[i]) continue;
            r = i - 1;
            break;
        }

        std::string ans = s.substr(0, l);
        std::string shifted_substr = s.substr(l + 1, r - l);
        shifted_substr += tail_char;
        ans += shifted_substr;
        ans += s.substr(r + 1);
        std::cout << ans << std::endl;
    }
    return 0;
}