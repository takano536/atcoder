#include <iostream>
#include <utility>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> coords(n);
    for (auto &[x, y] : coords) {
        std::cin >> x >> y;
    }

    for (int i = 0; i < n; i++) {
        int max_idx = -1;
        int max_dist = -1;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            auto x_diff = coords[i].first - coords[j].first;
            auto y_diff = coords[i].second - coords[j].second;

            auto dist = x_diff * x_diff + y_diff * y_diff;
            if (dist > max_dist) {
                max_dist = dist;
                max_idx = j;
            }
        }
        std::cout << max_idx + 1 << std::endl;
    }
    return 0;
}