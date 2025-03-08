#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
    std::vector<int> deck;
    for (int i = 0; i < 100; i++) deck.push_back(0);

    int q;
    std::cin >> q;

    while (q--) {
        int op;
        std::cin >> op;

        switch (op) {
            case 1: {
                int x;
                std::cin >> x;
                deck.push_back(x);
                break;
            }
            case 2: {
                std::cout << deck.back() << std::endl;
                deck.pop_back();
                break;
            }
            default: throw std::invalid_argument("Invalid input");
        }
    }
    return 0;
}