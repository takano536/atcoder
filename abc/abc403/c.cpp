#include <iostream>
#include <set>
#include <stdexcept>
#include <vector>

int main() {
    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<bool> is_admin(n);
    std::vector<std::set<int>> accessable_pages(n);

    while (q--) {
        int op;
        std::cin >> op;

        switch (op) {
            case 1: {
                int x, y;
                std::cin >> x >> y;
                x--, y--;
                if (is_admin[x]) continue;
                accessable_pages[x].insert(y);
                break;
            }
            case 2: {
                int x;
                std::cin >> x;
                x--;
                is_admin[x] = true;
                break;
            }
            case 3: {
                int x, y;
                std::cin >> x >> y;
                x--, y--;
                bool is_accessable = is_admin[x] || accessable_pages[x].contains(y);
                std::cout << (is_accessable ? "Yes" : "No") << std::endl;
                break;
            }
            default:
                throw std::invalid_argument("Invalid operation");
        }
    }

    return 0;
}