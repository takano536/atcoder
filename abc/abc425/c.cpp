#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<long long> cumsum(n * 2 + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> cumsum[i + 1];
        cumsum[i + n + 1] = cumsum[i + 1];
    }
    for (int i = 0; i < n * 2; i++) cumsum[i + 1] += cumsum[i];

    int head = 0;
    while (q--) {
        int op;
        std::cin >> op;
        switch (op) {
            case 1: {
                int c;
                std::cin >> c;
                head = (head + c) % n;
                break;
            }
            case 2: {
                int l, r;
                std::cin >> l >> r;
                l--, r--;
                std::cout << cumsum[head + r + 1] - cumsum[head + l] << std::endl;
                break;
            }
            default: std::runtime_error("invalid option");
        }
    }
}