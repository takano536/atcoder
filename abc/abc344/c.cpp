#include <iostream>
#include <set>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &ai : a) {
        std::cin >> ai;
    }

    int m;
    std::cin >> m;
    std::vector<int> b(m);
    for (auto &bi : b) {
        std::cin >> bi;
    }

    int l;
    std::cin >> l;
    std::vector<int> c(l);
    for (auto &ci : c) {
        std::cin >> ci;
    }

    std::set<int> sum_nums;
    for (const auto &ai : a) {
        for (const auto &bi : b) {
            for (const auto &ci : c) {
                sum_nums.insert(ai + bi + ci);
            }
        }
    }

    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        std::cin >> x;
        std::cout << (sum_nums.contains(x) ? "Yes" : "No") << std::endl;
    }
    return 0;
}