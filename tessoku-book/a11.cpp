#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, x;
    std::cin >> n >> x;

    std::vector<int> a(n);
    for (auto &num : a) {
        std::cin >> num;
    }

    std::cout << std::lower_bound(a.begin(), a.end(), x) - a.begin() + 1 << std::endl;
    return 0;
}