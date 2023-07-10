#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> a(n);
    for (auto &input : a) {
        std::cin >> input;
    }

    auto b = a;
    for (int i = 0; i < n - 1; i++) {
        b[0][i + 1] = a[0][i];
    }
    for (int i = 0; i < n - 1; i++) {
        b[i + 1][n - 1] = a[i][n - 1];
    }
    for (int i = 0; i < n - 1; i++) {
        b[n - 1][n - 2 - i] = a[n - 1][n - 1 - i];
    }
    for (int i = 0; i < n - 1; i++) {
        b[n - 2 - i][0] = a[n - 1 - i][0];
    }

    for (auto &output : b) {
        std::cout << output << std::endl;
    }
    return 0;
}