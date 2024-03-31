#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, a, b;
    std::cin >> n >> a >> b;
    std::vector<int> d(n);
    for (auto &di : d) {
        std::cin >> di;
    }

    for (int i = 0; i < n; i++) {
        d[i] %= (a + b);
    }
    std::ranges::sort(d);
    d.erase(std::unique(d.begin(), d.end()), d.end());
    std::vector<int> tmp(d.size() * 2);
    for (int i = 0; auto &di : tmp) {
        di = d[i];
        i = (i + 1) % d.size();
    }
    std::swap(d, tmp);

    bool is_satisfied = false;
    for (std::size_t i = 0; i < d.size() - 1; i++) {
        int interval = d[i] < d[i + 1] ? d[i + 1] - d[i] - 1 : a + b - d[i] + (d[i + 1] - 1);
        is_satisfied |= interval >= b;
    }

    std::cout << (is_satisfied ? "Yes" : "No") << std::endl;
    return 0;
}