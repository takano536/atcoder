#include <iostream>
#include <numeric>
#include <stdexcept>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    std::iota(a.begin(), a.end(), 1);

    int offset = 0;
    while (q--) {
        int op;
        std::cin >> op;

        switch (op) {
            case 1: {
                int p, x;
                std::cin >> p >> x;
                p--;
                a[(p + offset) % n] = x;
                break;
            }

            case 2: {
                int p;
                std::cin >> p;
                p--;
                std::cout << a[(p + offset) % n] << '\n';
                break;
            }

            case 3: {
                int k;
                std::cin >> k;
                offset = (offset + k) % n;
                break;
            }

            default: throw std::runtime_error("invalid option");
        }
    }

    std::cout << std::flush;
    return 0;
}