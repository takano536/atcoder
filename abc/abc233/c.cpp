#include <iostream>
#include <limits>
#include <vector>

int count(int idx, long long prod, const std::vector<std::vector<long long>> a, long long x) {
    if (idx == static_cast<int>(a.size())) {
        return static_cast<int>(prod == x);
    }
    int ans = 0;
    for (const auto &num : a[idx]) {
        if ((std::numeric_limits<long long>::max() / prod) < num) {
            continue;
        }
        ans += count(idx + 1, prod * num, a, x);
    }
    return ans;
}

int main() {
    int n;
    long long x;
    std::cin >> n >> x;
    std::vector a(n, std::vector<long long>());
    for (auto &ai : a) {
        int l;
        std::cin >> l;
        ai.resize(l);
        for (auto &aj : ai) {
            std::cin >> aj;
        }
    }

    std::cout << count(0, 1, a, x) << std::endl;
    return 0;
}