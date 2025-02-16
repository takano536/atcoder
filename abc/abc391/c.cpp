#include <iostream>
#include <numeric>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> nests(n, 1);
    std::vector<int> birds(n, 0);
    int ans = 0;
    std::iota(birds.begin(), birds.end(), 0);

    while (q--) {
        int opt;
        std::cin >> opt;

        switch (opt) {
            case 1: {
                int p, h;
                std::cin >> p >> h;
                p--, h--;
                if (nests[birds[p]] == 2) ans--;
                nests[birds[p]]--;
                birds[p] = h;
                if (nests[h] == 1) ans++;
                nests[h]++;
                break;
            }
            case 2:
                std::cout << ans << std::endl;
                break;
        }
    }
    return 0;
}