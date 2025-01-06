#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::map<int, long long> hol_sums;
    std::map<int, long long> ver_sums;
    std::map<int, std::vector<std::pair<int, long long>>> hol_nums;
    std::map<int, std::vector<std::pair<int, long long>>> ver_nums;
    for (int i = 0; i < n; i++) {
        int r, c, x;
        std::cin >> r >> c >> x;
        hol_sums[r] += x;
        ver_sums[c] += x;
        hol_nums[r].emplace_back(c, x);
        ver_nums[c].emplace_back(r, x);
    }

    auto find_max = [](auto &lhs_sums, auto &rhs_sums, auto &rhs_nums) {
        auto f = [](const auto &lhs, const auto &rhs) { return lhs.second < rhs.second; };
        auto sums = lhs_sums;
        const auto [rhs, rhs_max] = *std::ranges::max_element(rhs_sums, f);
        for (const auto &[lhs, duplication] : rhs_nums[rhs]) sums[lhs] -= duplication;
        const auto [_, lhs_max] = *std::ranges::max_element(sums, f);
        return lhs_max + rhs_max;
    };

    std::cout << std::max(find_max(ver_sums, hol_sums, hol_nums), find_max(hol_sums, ver_sums, ver_nums)) << std::endl;
    return 0;
}