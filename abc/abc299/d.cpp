#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int left = 1;
    int right = n;
    while (left + 1 < right) {
        int middle = static_cast<double>(left + right) / 2;
        std::cout << "? " << middle << std::endl << std::flush;
        char c;
        std::cin >> c;
        if (c == '0') {
            left = middle;
        } else {
            right = middle;
        }
    }
    std::cout << "! " << left << std::endl;
}