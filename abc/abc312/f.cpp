#include <algorithm>
#include <iostream>
#include <set>
#include <stdexcept>
#include <vector>

int main() {
    constexpr int INF = 1e9 + 1;

    std::size_t n, m;
    std::cin >> n >> m;

    std::multiset<int, std::greater<int>> que;
    std::vector<int> closed_cans, can_openers;
    long long ans = 0;
    for (std::size_t _ = 0; _ < n; _++) {
        int t, x;
        std::cin >> t >> x;
        switch (t) {
            case 0: que.insert(x), ans += x; break;
            case 1: closed_cans.push_back(x); break;
            case 2: can_openers.push_back(x); break;
            default: throw std::runtime_error("invalid t");
        }
    }

    std::ranges::sort(closed_cans);
    std::ranges::sort(can_openers, std::greater<int>());

    auto pop = [m](std::multiset<int, std::greater<int>> &que, long long curr_score) -> long long {
        while (que.size() > m) {
            auto worst_can_iter = std::prev(que.end());
            curr_score -= *worst_can_iter;
            que.erase(worst_can_iter);
        }
        return curr_score;
    };
    ans = pop(que, ans);

    long long curr_score = ans;
    for (const auto &can_opener : can_openers) {
        if (closed_cans.empty()) break;

        que.insert(INF);

        for (int _ = 0; _ < can_opener; _++) {
            if (closed_cans.empty()) break;

            int curr_can = closed_cans.back();
            closed_cans.pop_back();

            que.insert(curr_can);
            curr_score += curr_can;
            curr_score = pop(que, curr_score);

            ans = std::max(curr_score, ans);
        }
    }

    std::cout << ans << std::endl;
    return 0;
}