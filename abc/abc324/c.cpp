#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::string t;
    std::cin >> t;
    int t_len = t.size();

    std::vector<int> ans;
    for (int i = 1; i <= n; i++) {
        std::string s;
        std::cin >> s;
        int s_len = s.size();

        if (s == t) {
            ans.push_back(i);
            continue;
        }
        if (std::abs(s_len - t_len) > 1) {
            continue;
        }

        int prefix_len = 0;
        for (int s_idx = 0, t_idx = 0; s[s_idx] == t[t_idx]; s_idx++, t_idx++) {
            prefix_len++;
        }
        int suffix_len = 0;
        for (int s_idx = s_len - 1, t_idx = t_len - 1; s[s_idx] == t[t_idx]; s_idx--, t_idx--) {
            suffix_len++;
        }
        if (std::max(s_len, t_len) - (prefix_len + suffix_len) <= 1) {
            ans.push_back(i);
        }
    }

    std::cout << ans.size() << std::endl;
    for (const int &idx : ans) {
        std::cout << idx << ' ';
    }
    std::cout << std::endl;
}