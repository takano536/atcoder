#include <iostream>
#include <map>
#include <stdexcept>

int main() {
    constexpr int TAIL = -3;
    constexpr int HEAD = -2;

    int n;
    std::cin >> n;

    std::map<int, int> tails, heads;
    tails[0] = TAIL, heads[0] = HEAD;
    tails[HEAD] = 0, heads[TAIL] = 0;

    for (int i = 1; i <= n; i++) {
        char c;
        std::cin >> c;
        switch (c) {
            case 'L': {
                tails[i] = tails[i - 1];
                heads[tails[i - 1]] = i;
                tails[i - 1] = i;
                heads[i] = i - 1;
                break;
            }
            case 'R': {
                tails[i] = i - 1;
                heads[i] = heads[i - 1];
                tails[heads[i - 1]] = i;
                heads[i - 1] = i;
                break;
            }
            default:
                throw std::runtime_error("invalid input");
        }
    }

    int curr = heads[TAIL];
    for (int i = 0; i <= n; i++) {
        std::cout << curr << ' ';
        curr = heads[curr];
    }
    std::cout << std::endl;
    return 0;
}