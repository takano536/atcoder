#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<std::pair<int, int>> coords(n);
    for (auto &[x, y] : coords) std::cin >> x >> y;

    std::vector<long long> rotate_x(n), rotate_y(n);
    for (int i = 0; i < n; i++) {
        auto &[x, y] = coords[i];
        rotate_x[i] = x + y;
        rotate_y[i] = x - y;
    }

    std::ranges::sort(rotate_x);
    std::ranges::sort(rotate_y);

    while (q--) {
        int query;
        std::cin >> query;
        query--;

        const auto &[qx, qy] = coords[query];
        const long long rotate_qx = qx + qy;
        const long long rotate_qy = qx - qy;
        auto max_x = std::max(std::abs(rotate_x[0] - rotate_qx), std::abs(rotate_x[n - 1] - rotate_qx));
        auto max_y = std::max(std::abs(rotate_y[0] - rotate_qy), std::abs(rotate_y[n - 1] - rotate_qy));
        std::cout << std::max(max_x, max_y) << std::endl;
    }
    return 0;
}