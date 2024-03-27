#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (auto &ai : a) {
        std::cin >> ai;
    }
    std::ranges::sort(a);

    for (int query = 0; query < q; query++) {
        int x;
        std::cin >> x;
        std::cout << std::distance(std::ranges::lower_bound(a, x), a.end()) << std::endl;
    }
    return 0;
}