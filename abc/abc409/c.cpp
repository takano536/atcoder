#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, l;
    std::cin >> n >> l;

    std::vector<int> d(n - 1);
    for (auto &di : d) std::cin >> di;

    if (l % 3 != 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<int> points(l);
    int curr = 0;
    points[curr]++;
    for (const auto di : d) {
        curr += di;
        curr %= l;
        points[curr]++;
    }

    int dist = l / 3;
    long long ans = 0;
    for (int i = 0; i < l; i++) {
        int a = i;
        int b = (i + dist) % l;
        int c = (i + 2 * dist) % l;
        ans += static_cast<long long>(points[a]) * points[b] * points[c];
    }
    std::cout << ans / 3 << std::endl;
    return 0;
}