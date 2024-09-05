#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    auto calc_lis = [](const std::vector<int> &nums) {
        const int n = nums.size();
        std::vector<int> lis{0};
        std::vector<int> ret(n);
        for (int i = 0; i < n; i++) {
            auto iter = std::ranges::lower_bound(lis, nums[i]);
            if (iter == lis.end()) {
                lis.push_back(nums[i]);
            } else if (*iter != nums[i]) {
                lis[std::distance(lis.begin(), iter)] = nums[i];
            }
            ret[i] = lis.size() - 1;
        }
        return ret;
    };

    auto rev_a = a;
    std::ranges::reverse(rev_a);

    auto lis = calc_lis(a);
    auto rev_lis = calc_lis(rev_a);

    int ans = 0;
    for (int i = 0; i < n; i++) ans = std::max(lis[i] + rev_lis[n - 1 - i], ans);

    std::cout << ans - 1 << std::endl;
    return 0;
}