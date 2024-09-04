#include <iostream>
#include <vector>

#include <atcoder/modint>

int main() {
    constexpr int NUM = 5;

    int n, p, q;
    std::cin >> n >> p >> q;
    atcoder::modint::set_mod(p);

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    int ans = 0;
    auto f = [&](auto &&f, std::vector<int> &nums, const int last_idx) -> void {
        if (nums.size() == NUM) {
            atcoder::modint mul = 1;
            for (const auto &num : nums) mul *= num;
            if (mul == q) ans++;
            return;
        }
        for (int i = last_idx + 1; i < n; i++) {
            nums.push_back(a[i]);
            f(f, nums, i);
            nums.pop_back();
        }
        return;
    };

    std::vector<int> nums;
    f(f, nums, -1);
    std::cout << ans << std::endl;
    return 0;
}