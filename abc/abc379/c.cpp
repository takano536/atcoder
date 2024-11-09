#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> stones(m);
    long long cnts = 0;
    for (auto &[x, _] : stones) std::cin >> x, x--;
    for (auto &[_, a] : stones) std::cin >> a, cnts += a;

    std::ranges::sort(stones);

    if (cnts != n || stones[0].first != 0) {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::set<int> used_cells;
    for (const auto &[x, _] : stones) used_cells.insert(x);
    used_cells.insert(n);

    long long ans = 0;
    auto iter = used_cells.begin();
    for (int i = 0; i < m; i++) {
        const auto &[_, curr_cnt] = stones[i];
        int diff = *std::next(iter) - *iter;
        int empty_cnt = diff - 1;
        if (diff > curr_cnt || (i == m - 1 && diff != curr_cnt)) {
            std::cout << -1 << std::endl;
            return 0;
        }
        ans += static_cast<long long>(empty_cnt) * (empty_cnt + 1) / 2;
        ans += static_cast<long long>(curr_cnt - empty_cnt - 1) * diff;
        if (i != m - 1) stones[i + 1].second += curr_cnt - diff;
        iter++;
    }

    std::cout << ans << std::endl;
    return 0;
}