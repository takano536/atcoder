#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    std::string ans;
    int w_cnt = 0;
    for (auto c : s) {
        if (c == 'W') {
            w_cnt++;
        } else if (w_cnt > 0 && c == 'A') {
            ans += 'A' + std::string(w_cnt, 'C');
            w_cnt = 0;
        } else {
            if (w_cnt > 0) {
                ans += std::string(w_cnt, 'W');
                w_cnt = 0;
            }
            ans += c;
        }
    }
    if (w_cnt > 0) {
        ans += std::string(w_cnt, 'W');
    }

    std::cout << ans << std::endl;
    return 0;
}