#include <iostream>

int main() {
    const int MAX_ANS = 9999;

    int n;
    std::cin >> n;

    int a, b, c;
    std::cin >> a >> b >> c;

    int ans = 1e5;
    for (int i = 0; i <= MAX_ANS; i++) {
        for (int j = 0; j <= MAX_ANS; j++) {
            long shortage = static_cast<long>(n) - i * a - j * b;
            if (shortage < 0) {
                continue;
            }
            if (shortage % c != 0) {
                continue;
            }
            ans = std::min(ans, i + j + static_cast<int>(shortage / c));
        }
    }

    std::cout << ans << std::endl;
    return 0;
}