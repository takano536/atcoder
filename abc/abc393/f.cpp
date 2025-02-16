#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    std::vector<std::pair<std::pair<int, int>, int>> queries(q);
    for (int i = 0; auto &[query, idx] : queries) {
        auto &[r, x] = query;
        std::cin >> r >> x;
        r--;
        idx = i++;
    }

    std::ranges::sort(queries);
    int query_idx = 0;

    std::vector<int> ans(q);

    std::vector<int> lis{0};
    for (int i = 0; i < n; i++) {
        auto iter = std::ranges::lower_bound(lis, a[i]);
        if (iter == lis.end()) {
            lis.push_back(a[i]);
        } else if (*iter != a[i]) {
            lis[std::distance(lis.begin(), iter)] = a[i];
        }

        while (query_idx < q) {
            auto &[query, idx] = queries[query_idx];
            auto &[r, x] = query;
            if (r > i) break;

            ans[idx] = std::distance(lis.begin(), std::prev(std::ranges::upper_bound(lis, x)));
            query_idx++;
        }
    }

    for (const auto &ai : ans) std::cout << ai << std::endl;
    return 0;
}