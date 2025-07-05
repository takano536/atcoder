#include <algorithm>
#include <iostream>
#include <vector>

bool is_geometric(const std::vector<long long> &a) {
    for (size_t i = 0; i < a.size() - 2; i++) {
        if (a[i] * a[i + 2] != a[i + 1] * a[i + 1]) return false;
    }
    return true;
}

std::string solve() {
    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    int pos_count = 0, neg_count = 0;
    for (auto &ai : a) std::cin >> ai, (ai > 0 ? pos_count : neg_count)++;

    auto is_equal_abs = std::ranges::all_of(a, [&a](const auto &ai) { return std::abs(ai) == std::abs(*a.begin()); });

    if (is_equal_abs && pos_count > 0 && neg_count > 0) {
        return std::abs(pos_count - neg_count) > 1 ? "No" : "Yes";
    }

    std::ranges::sort(a, std::less(), [](const auto &ai) { return std::abs(ai); });
    return is_geometric(a) ? "Yes" : "No";
}

int main() {
    int t;
    std::cin >> t;

    while (t--) std::cout << solve() << '\n';

    std::cout << std::flush;
    return 0;
}