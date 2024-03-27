#include <iostream>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> coords(n);
    for (auto &[x, y] : coords) {
        std::cin >> x >> y;
    }

    std::set<std::pair<int, int>> magics;
    for (const auto &[x1, y1] : coords) {
        for (const auto &[x2, y2] : coords) {
            if (x1 == x2 && y1 == y2) {
                continue;
            }
            auto diff = std::make_pair(x1 - x2, y1 - y2);
            auto gcd = std::gcd(diff.first, diff.second);
            magics.insert({diff.first / gcd, diff.second / gcd});
        }
    }

    std::cout << magics.size() << std::endl;
    return 0;
}