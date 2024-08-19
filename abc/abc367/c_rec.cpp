#include <iostream>
#include <numeric>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> r(n);
    for (auto &ri : r) std::cin >> ri;

    auto f = [&](auto &&f, std::vector<int> &a) {
        if (a.size() == static_cast<std::size_t>(n)) {
            if (std::accumulate(a.begin(), a.end(), 0) % k) return;
            for (const auto &ans : a) std::cout << ans << ' ';
            std::cout << std::endl;
            return;
        }
        for (int next = 1; next <= r[a.size()]; next++) {
            a.push_back(next);
            f(f, a);
            a.pop_back();
        }
        return;
    };

    std::vector<int> a;
    f(f, a);
    return 0;
}