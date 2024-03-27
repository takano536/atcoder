#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#include <atcoder/dsu>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector merge_queries(n, std::vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        if (a > b) {
            std::swap(a, b);
        }
        merge_queries[a].push_back(b);
    }

    std::vector<int> nums = {0};
    auto curr_num = 0;
    atcoder::dsu union_find(n);
    for (int i = n - 1; i > 0; i--) {
        curr_num++;
        for (auto to : merge_queries[i]) {
            if (union_find.same(to, i)) {
                continue;
            }
            union_find.merge(to, i);
            curr_num--;
        }
        nums.push_back(curr_num);
    }

    std::ranges::reverse(nums);
    for (const auto &ans : nums) {
        std::cout << ans << std::endl;
    }

    return 0;
}