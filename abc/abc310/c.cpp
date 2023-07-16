#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::map<std::string, int> m;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        std::string reversed_s = s;
        std::reverse(reversed_s.begin(), reversed_s.end());
        if (s == reversed_s) {
            s += "_";
            reversed_s = "_" + reversed_s;
        }
        m[s]++;
        m[reversed_s]++;
    }

    std::cout << m.size() / 2 << std::endl;
}