#include <iostream>
#include <vector>

int main() {
    long n;
    std::cin >> n;

    for (int i = 2; i <= 3; i++) {
        if (n % i != 0) {
            continue;
        }

        while (n % i == 0) {
            n /= i;
        }
    }

    std::cout << (n == 1 ? "Yes" : "No") << std::endl;
    return 0;
}