#include <iostream>
#include <set>

int main() {
    long long n;
    std::cin >> n;

    std::set<long long> ans = {0LL};

    for (int i = 0; i < 60; i++) {
        std::set<long long> nums;
        if (!(n & (1LL << i))) continue;
        for (const auto &num : ans) nums.insert(num + (1LL << i));
        ans.merge(nums);
    }

    for (const auto &num : ans) std::cout << num << std::endl;
    return 0;
}