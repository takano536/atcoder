#include <iostream>
#include <numeric>
#include <stdexcept>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> birds(n + 1);
    std::iota(birds.begin(), birds.end(), 0);

    std::vector<int> nests(n + 1), nests2nests(n + 1);
    std::iota(nests.begin(), nests.end(), 0);
    std::iota(nests2nests.begin(), nests2nests.end(), 0);

    while (q--) {
        int op;
        std::cin >> op;

        switch (op) {
            case 1: {
                int a, b;
                std::cin >> a >> b;
                birds[a] = nests[b];
                break;
            }

            case 2: {
                int a, b;
                std::cin >> a >> b;
                std::swap(nests[a], nests[b]);
                nests2nests[nests[a]] = a;
                nests2nests[nests[b]] = b;
                break;
            }

            case 3: {
                int a;
                std::cin >> a;
                std::cout << nests2nests[birds[a]] << std::endl;
                break;
            }

            default:
                throw std::runtime_error("Invalid input");
        }
    }
    return 0;
}