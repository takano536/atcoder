#include <iostream>
#include <map>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::map<std::string, int> cnts;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        std::cout << (cnts.contains(s) ? s + '(' + std::to_string(cnts[s]) + ')' : s) << std::endl;
        cnts[s]++;
    }
    return 0;
}