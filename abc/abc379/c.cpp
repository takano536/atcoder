#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> stones(m);
    for (auto &[x, _] : stones) std::cin >> x, x--;
    for (auto &[_, a] : stones) std::cin >> a;
    stones.emplace_back(-1, 1);
    stones.emplace_back(n, 1);

    std::ranges::sort(stones);

    long long ans = 0;
    for (int i = 0; i <= m; i++) {
        const auto &[curr_coord, curr_num] = stones[i];
        auto &[next_coord, next_num] = stones[i + 1];

        const int available_num = curr_num - 1;
        const int blank_num = next_coord - curr_coord - 1;

        if (available_num < blank_num) {
            std::cout << -1 << std::endl;
            return 0;
        }
        ans += static_cast<long long>(blank_num + 1) * blank_num / 2;

        const int excess_num = available_num - blank_num;
        next_num += excess_num;

        const int cost = next_coord - curr_coord;
        ans += static_cast<long long>(excess_num) * cost;
    }

    std::cout << ans << std::endl;
    return 0;
}