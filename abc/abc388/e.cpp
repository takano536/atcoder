#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    int ok = 0, ng = (n + 2 - 1) / 2 + 1;
    while (ng - ok > 1) {
        const int mid = (ok + ng) / 2;
        std::multiset<int> smalls;
        for (int i = 0; i < mid; i++) smalls.insert(-a[i]);

        for (int i = n - 1; i >= mid; i--) {
            const int threshold = a[i] / 2;
            const auto iter = smalls.lower_bound(-threshold);
            if (iter != smalls.end()) smalls.erase(iter);
            if (smalls.empty()) break;
        }

        (smalls.empty() ? ok : ng) = mid;
    }

    std::cout << ok << std::endl;
    return 0;
}
