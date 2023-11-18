#include <iostream>
#include <map>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::map<char, int> mp;
    mp[s[0]] = 1;
    int cnt = 1;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) {
            mp[s[i]] = std::max(mp[s[i]], cnt);
            cnt = 1;
        } else {
            cnt++;
        }
    }
    mp[s[n - 1]] = std::max(mp[s[n - 1]], cnt);

    int ans = 0;
    for (const auto &[key, value] : mp) {
        ans += value;
    }
    std::cout << ans << std::endl;
    return 0;
}