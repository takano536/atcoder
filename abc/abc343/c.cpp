#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int main() {
    int MAX_N = std::cbrtl(1e18);
    long long n;
    std::cin >> n;

    for (long long i = MAX_N; i >= 1; i--) {
        if (i * i * i > n) {
            continue;
        }
        std::string str = std::to_string(i * i * i);
        std::string rev = str;
        std::ranges::reverse(rev);
        if (str == rev) {
            std::cout << i * i * i << std::endl;
            break;
        }
    }
    return 0;
}