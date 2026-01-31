#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> r(n);
    for (auto &ri : r) std::cin >> ri;

    const auto r_min = *std::ranges::min_element(r);
    for (auto &ri : r) ri -= r_min;

    std::queue<int> que;
    std::vector<std::vector<int>> idxes(n);
    std::vector<bool> has_completed(n);
    for (int i = 0; const auto &ri : r) {
        if (ri == 0) que.push(i), has_completed[i] = true;
        if (ri > 0) idxes[ri].push_back(i);
        i++;
    }

    long long ans = 0;
    while (!que.empty()) {
        const auto i = que.front();
        que.pop();

        if (!idxes[r[i]].empty()) {
            for (const auto j : idxes[r[i]]) que.push(j), idxes[r[i]].pop_back();
        }

        if (i > 0 && !has_completed[i - 1]) {
            que.push(i - 1);
            has_completed[i - 1] = true;
            if (std::abs(r[i - 1] - r[i]) > 1) {
                ans += (r[i - 1] - r[i] - 1);
                r[i - 1] = r[i] + 1;
            }
        }
        if (i < n - 1 && !has_completed[i + 1]) {
            que.push(i + 1);
            has_completed[i + 1] = true;
            if (std::abs(r[i + 1] - r[i]) > 1) {
                ans += (r[i + 1] - r[i] - 1);
                r[i + 1] = r[i] + 1;
            }
        }
    }

    std::cout << ans << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}