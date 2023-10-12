#include <iostream>

long exp(int a, int b) {
    long ans = 1;
    for (int i = 0; i < b; i++) {
        ans *= a;
    }
    return ans;
}

int main() {
    long a;
    int b, c;
    std::cin >> a >> b >> c;
    std::cout << (a < exp(c, b) ? "Yes" : "No") << std::endl;
    return 0;
}