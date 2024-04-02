#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::string> s(n);
    for (auto &si : s) {
        std::cin >> si;
    }

    int ans = 0;
    for (int bit = 0; bit < (1 << n); bit++) {
        std::vector<int> cnts(26);
        for (int i = 0; i < n; i++) {
            if (!(bit & (1 << i))) {
                continue;
            }
            for (const auto &c : s[i]) {
                cnts[c - 'a']++;
            }
        }
        ans = std::max(ans, static_cast<int>(std::ranges::count(cnts, k)));
    }

    std::cout << ans << std::endl;
    return 0;
}