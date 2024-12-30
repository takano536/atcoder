#include <algorithm>
#include <iostream>
#include <string>

int main() {
    int k;
    std::cin >> k;

    std::string s, t;
    std::cin >> s >> t;

    while (s.back() == t.back() && !s.empty() && !t.empty()) {
        s.pop_back();
        t.pop_back();
    }

    std::ranges::reverse(s);
    std::ranges::reverse(t);

    while (s.back() == t.back() && !s.empty() && !t.empty()) {
        s.pop_back();
        t.pop_back();
    }

    std::cout << (s.size() <= 1 && t.size() <= 1 ? "Yes" : "No") << std::endl;
    return 0;
}