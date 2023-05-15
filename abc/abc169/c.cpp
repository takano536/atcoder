#include <iostream>

int main() {
    const double EPS = 1e-3;
    long double a, b;
    std::cin >> a >> b;

    std::cout << static_cast<long long>(a * b + EPS) << std::endl;
    return 0;
}