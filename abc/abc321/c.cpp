#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

int main() {
    int k;
    std::cin >> k;
    k--;

    std::vector<long long> like_nums;
    for (int i = 1; i <= 9; ++i) {
        like_nums.push_back(i);
    }

    auto dfs = [&](auto dfs, long long num) {
        int last_digit = num % 10;
        if (last_digit == 0) {
            return;
        }
        std::string num_str = std::to_string(num);
        for (int i = last_digit - 1; i >= 0; i--) {
            std::string curr_str = num_str + std::to_string(i);
            long long curr_num = std::stoll(curr_str);
            like_nums.push_back(curr_num);
            dfs(dfs, curr_num);
        }
        return;
    };

    for (int i = 1; i <= 9; ++i) {
        dfs(dfs, i);
    }

    std::ranges::sort(like_nums);
    std::cout << like_nums[k] << std::endl;
    return 0;
}