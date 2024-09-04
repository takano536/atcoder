#include <iostream>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    int offset = 0;
    while (q--) {
        int t, x, y;
        std::cin >> t >> x >> y;

        const auto x_idx = (x - 1 - offset + n) % n;
        const auto y_idx = (y - 1 - offset + n) % n;

        switch (t) {
            case 1:
                std::swap(a[x_idx], a[y_idx]);
                break;

            case 2:
                offset = (offset + 1) % n;
                break;

            case 3:
                std::cout << a[x_idx] << std::endl;
                break;

            default:
                return -1;
        }
    }
    return 0;
}