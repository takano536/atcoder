#include <iostream>
#include <numeric>
#include <vector>

#include <atcoder/modint>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> nums(n + 1);
    std::iota(nums.begin(), nums.end(), 0);

    std::vector<long long> nums_cumsum(nums.size() + 1);
    for (std::size_t i = 0; i < nums.size(); i++) nums_cumsum[i + 1] = nums_cumsum[i] + nums[i];

    atcoder::modint1000000007 ans;
    for (std::size_t i = k; i <= nums.size(); i++) {
        long long min_sum = nums_cumsum[i] - nums_cumsum[0];
        long long max_sum = nums_cumsum[nums.size()] - nums_cumsum[nums.size() - i];
        ans += max_sum - min_sum + 1;
    }

    std::cout << ans.val() << std::endl;
    return 0;
}