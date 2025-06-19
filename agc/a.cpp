#include <iostream>
#include <map>
#include <numeric>
#include <ranges>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    for (auto &ai : a) std::cin >> ai;

    std::vector<long long> cumsum = {0};
    std::partial_sum(a.begin(), a.end(), std::back_inserter(cumsum));

    std::map<long long, int> cumsum_counts;
    for (const auto &sum : cumsum) cumsum_counts[sum]++;

    long long ans = 0;
    for (const auto &count : std::views::values(cumsum_counts)) {
        ans += static_cast<long long>(count) * (count - 1) / 2;
    }

    std::cout << ans << std::endl;
    return 0;
}