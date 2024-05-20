#include <iomanip>
#include <iostream>

int main() {
    int n;
    std::cin >> n;
    if (n >= 42) n++;
    std::cout << "AGC" << std::setfill('0') << std::setw(3) << n << std::endl;
    return 0;
}