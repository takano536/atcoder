#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) std::cin >> x[i] >> y[i];

    auto median = [](std::vector<int> &nums) -> long long {
        std::ranges::sort(nums);
        return nums[nums.size() / 2];
    };

    long long ans = 0;
    auto med_x = median(x);
    auto med_y = median(y);
    for (int i = 0; i < n; i++) {
        ans += std::abs(med_x - x[i]);
        ans += std::abs(med_y - y[i]);
    }

    std::cout << ans << std::endl;
    return 0;
}