#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int ans = 0;
    for (auto iter = s.begin(); iter != s.end(); iter++, ans++) {
        if ('1' <= *iter && *iter <= '9') continue;
        if (std::next(iter) != s.end() && *std::next(iter) == '0') iter++;
    }

    std::cout << ans << std::endl;
    return 0;
}