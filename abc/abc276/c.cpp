#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> p(n);
    for (auto &pi : p) std::cin >> pi;

    std::ranges::prev_permutation(p);
    for (auto &pi : p) std::cout << pi << ' ';
    std::cout << std::endl;
    return 0;
}