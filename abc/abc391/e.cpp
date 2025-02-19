#include <iostream>
#include <numeric>
#include <set>
#include <vector>

int powi(int x, int y) {
    int ret = 1;
    for (int i = 0; i < y; i++) ret *= x;
    return ret;
}

int ceili(int x, int y) {
    return (x + y - 1) / y;
}

int main() {
    constexpr int SUBSET_SIZE = 3;

    int n;
    std::cin >> n;

    std::vector<bool> a(powi(SUBSET_SIZE, n));
    for (auto ai : a) {
        char c;
        std::cin >> c;
        ai = (c == '1');
    }

    std::vector dp(a.size(), std::vector<int>(2));
    for (std::size_t i = 0; i < a.size(); i++) dp[i][!a[i]] = 1;

    while (dp.size() > 1) {

        std::vector prev(dp.size() / SUBSET_SIZE, std::vector<int>(2));
        std::swap(dp, prev);

        for (std::size_t i = 0; i < dp.size(); i++) {

            std::vector<std::multiset<int>> costs(2);
            for (int j = 0; j < SUBSET_SIZE; j++) {
                const int prev_idx = i * SUBSET_SIZE + j;
                if (prev[prev_idx][0] != 0) costs[0].insert(prev[prev_idx][0]);
                if (prev[prev_idx][1] != 0) costs[1].insert(prev[prev_idx][1]);
            }

            auto flip_elem = (costs[0].size() > costs[1].size() ? 0 : 1);
            const int flip_num = ceili(costs[flip_elem].size(), 2);

            const auto sum_head = costs[flip_elem].begin();
            const auto sum_tail = std::next(sum_head, flip_num);
            dp[i][flip_elem] = std::accumulate(sum_head, sum_tail, 0);
        }
    }

    std::cout << std::max(dp[0][0], dp[0][1]) << std::endl;
    return 0;
}