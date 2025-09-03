#include <array>
#include <iostream>
#include <string>

int main() {
    constexpr int N = 4;
    constexpr int DESIRED_NUM = 7;

    std::array<int, N> nums;
    for (auto &num : nums) {
        char c;
        std::cin >> c;
        num = c - '0';
    }

    std::string ans;
    for (int bit = 0; bit < (1 << (N - 1)); bit++) {
        int ret = nums[0];
        ans = std::to_string(nums[0]);
        for (int i = 0; i < N - 1; i++) {
            ans += (bit & (1 << i) ? '+' : '-') + std::to_string(nums[i + 1]);
            ret += (bit & (1 << i) ? +nums[i + 1] : -nums[i + 1]);
        }
        if (ret == DESIRED_NUM) break;
    }

    ans += "=7";
    std::cout << ans << std::endl;
    return 0;
}