#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

int main() {
    int q;
    std::cin >> q;
    std::vector<int> cumsum = {0};
    std::string t;
    int minus_elem_count = 0;

    for (int i = 1; i <= q; i++) {
        int op;
        std::cin >> op;

        switch (op) {
            case 1: {
                char c;
                std::cin >> c;
                t += c;
                cumsum.push_back(cumsum.back() + (c == '(' ? +1 : -1));
                if (cumsum.back() < 0) minus_elem_count++;
                break;
            }
            case 2:
                if (cumsum.back() < 0) minus_elem_count--;
                cumsum.pop_back();
                t.pop_back();
                break;

            default: std::runtime_error("invalid option");
        }

        std::cout << (minus_elem_count == 0 && cumsum.back() == 0 ? "Yes" : "No") << '\n';
    }

    std::cout << std::flush;
    return 0;
}