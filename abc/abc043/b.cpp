#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    std::string ans;
    for (auto &c : s) {
        switch (c) {
            case 'B':
                if (ans.size() > 0) ans.pop_back();
                break;
            default:
                ans += c;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}