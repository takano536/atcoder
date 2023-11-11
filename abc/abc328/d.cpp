#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    std::string ans;
    for (const auto &c : s) {
        ans += c;
        if (ans.size() < 3) {
            continue;
        }
        while (1) {
            int len = ans.size();
            if (ans[len - 1] == 'C' && ans[len - 2] == 'B' && ans[len - 3] == 'A') {
                ans.pop_back();
                ans.pop_back();
                ans.pop_back();
            } else {
                break;
            }
        }
    }

    std::cout << ans << std::endl;
    return 0;
}