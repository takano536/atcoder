#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<std::string, int>> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i].first;
        s[i].second = i;
    }

    std::sort(s.begin(), s.end());

    auto count = [](std::string s1, std::string s2) {
        int n = s1.size();
        int m = s2.size();
        int i = 0;
        while (i < n && i < m && s1[i] == s2[i]) {
            i++;
        }
        return i;
    };

    std::vector<int> ans(n);
    ans[s[0].second] = count(s[0].first, s[1].first);
    ans[s[n - 1].second] = count(s[n - 1].first, s[n - 2].first);

    for (int i = 1; i < n - 1; i++) {
        ans[s[i].second] = std::max(count(s[i].first, s[i - 1].first), count(s[i].first, s[i + 1].first));
    }

    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << std::endl;
    }
    return 0;
}