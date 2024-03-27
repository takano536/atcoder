#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> p(n);
    for (auto &pi : p) {
        std::cin >> pi;
    }

    std::set<int, std::greater<int>> desc_seq = std::set<int, std::greater<int>>(p.begin(), p.begin() + k);
    for (int i = k; i < n; i++) {
        std::cout << *desc_seq.rbegin() << std::endl;
        if (p[i] > *desc_seq.rbegin()) {
            desc_seq.insert(p[i]);
            desc_seq.erase(std::prev(desc_seq.end()));
        }
    }
    std::cout << *desc_seq.rbegin() << std::endl;
    return 0;
}