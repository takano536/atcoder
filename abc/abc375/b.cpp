#include <cmath>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<long long, long long>> coords(n);
    for (auto &[x, y] : coords) std::cin >> x >> y;
    coords.push_back({0, 0});

    long double ans = 0;
    std::pair<long long, long long> curr = {0, 0};
    for (const auto &[x, y] : coords) {
        ans += std::sqrt((x - curr.first) * (x - curr.first) + (y - curr.second) * (y - curr.second));
        curr = {x, y};
    }

    std::printf("%.10Lf\n", ans);
    return 0;
}