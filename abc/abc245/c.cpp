#include <iostream>
#include <utility>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n), b(n);
    for (auto &ai : a) {
        std::cin >> ai;
    }
    for (auto &bi : b) {
        std::cin >> bi;
    }

    const int NA = 0;
    std::pair<int, int> tails = {a[0], b[0]};
    std::pair<int, int> next = {NA, NA};
    for (int i = 1; i < n; i++) {
        next = {NA, NA};
        if (tails.first != NA && std::abs(tails.first - a[i]) <= k) {
            next.first = a[i];
        }
        if (tails.first != NA && std::abs(tails.first - b[i]) <= k) {
            next.second = b[i];
        }
        if (tails.second != NA && std::abs(tails.second - a[i]) <= k) {
            next.first = a[i];
        }
        if (tails.second != NA && std::abs(tails.second - b[i]) <= k) {
            next.second = b[i];
        }
        tails = next;
    }

    std::cout << (tails.first != NA || tails.second != NA ? "Yes" : "No") << std::endl;
    return 0;
}