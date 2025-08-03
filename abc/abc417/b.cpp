#include <iostream>
#include <set>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::multiset<int> a;
    for (int i = 0; i < n; i++) {
        int ai;
        std::cin >> ai;
        a.insert(ai);
    }

    for (int i = 0; i < m; i++) {
        int bi;
        std::cin >> bi;
        auto iter = a.lower_bound(bi);
        if (iter == a.end() || *iter != bi) continue;
        a.erase(iter);
    }

    for (const auto &ai : a) std::cout << ai << ' ';
    std::cout << std::endl;
    return 0;
}