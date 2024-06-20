#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::string ans;
    bool is_enclosed = false;
    for (const auto &c : s) {
        if (c == '"') is_enclosed = !is_enclosed;
        ans += (!is_enclosed && c == ',' ? '.' : c);
    }

    std::cout << ans << std::endl;
    return 0;
}