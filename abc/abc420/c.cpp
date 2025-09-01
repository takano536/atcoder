#include <iostream>
#include <ranges>
#include <utility>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<std::pair<int, int>> nums(n);
    for (auto &a : std::views::keys(nums)) std::cin >> a;
    for (auto &b : std::views::values(nums)) std::cin >> b;

    long long ans = 0;
    for (const auto &[a, b] : nums) ans += std::min(a, b);

    while (q--) {
        char c;
        int x, v;
        std::cin >> c >> x >> v;
        auto &[a, b] = nums[x - 1];
        const auto prev_min = std::min(a, b);
        (c == 'A' ? a : b) = v;
        if (std::min(a, b) != prev_min) ans += std::min(a, b) - prev_min;
        std::cout << ans << std::endl;
    }
    return 0;
}