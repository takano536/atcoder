#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, d;
    std::cin >> n >> d;

    std::vector<std::pair<int, int>> walls(n);
    for (auto &wall : walls) {
        std::cin >> wall.first >> wall.second;
    }

    std::sort(walls.begin(), walls.end(), [](const auto &lhs, const auto &rhs) { return lhs.second < rhs.second; });

    int ans = 1;
    int curr_row = walls[0].second;
    for (const auto &[l, r] : walls) {
        if (l <= curr_row + d - 1) {
            continue;
        }
        curr_row = r;
        ans++;
    }

    std::cout << ans << std::endl;
    return 0;
}