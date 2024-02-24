#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> p(n);
    for (auto &pi : p) {
        std::cin >> pi;
    }

    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;
        for (int i = 0; i < n; i++) {
            if (p[i] == l || p[i] == r) {
                std::cout << p[i] << std::endl;
                break;
            }
        }
    }
    return 0;
}