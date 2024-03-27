#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::vector<int> cnts(26);
    bool contains = false;
    for (const auto &c : s) {
        cnts[c - 'a']++;
        if (cnts[c - 'a'] > 1) {
            contains = true;
        }
    }
    long long ans = static_cast<int>(contains);
    for (int i = 0; i < n; i++) {
        cnts[s[i] - 'a']--;
        ans += (n - i - 1 - cnts[s[i] - 'a']);
    }
    std::cout << ans << std::endl;
}