#include <iostream>

int main() {
    int t;
    std::cin >> t;

    for (int testcase = 0; testcase < t; testcase++) {
        unsigned long long a, s;
        std::cin >> a >> s;
        auto x = a;
        auto y = s - a * 2;
        std::cout << (a <= s && (x & y) == 0 ? "Yes" : "No") << std::endl;
    }
    return 0;
}