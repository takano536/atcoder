#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, k;
    long long x;
    std::cin >> n >> k >> x;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    std::ranges::sort(a, std::ranges::greater());

    int ans = 0;
    long long total = 0;
    for (int i = 0; const auto &ai : a) {
        ans++;
        if (i >= n - k) total += ai;
        if (total >= x) break;
        i++;
    }

    std::cout << (total >= x ? ans : -1) << std::endl;
    return 0;
}