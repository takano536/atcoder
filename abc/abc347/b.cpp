#include <iostream>
#include <set>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    std::set<std::string> substrs;
    for (int i = 0; i < static_cast<int>(s.size()); i++) {
        for (int j = i; j < static_cast<int>(s.size()); j++) {
            substrs.insert(s.substr(i, j - i + 1));
        }
    }
    std::cout << substrs.size() << std::endl;
    return 0;
}