#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<long long, long long>> intervals(n);
    for (auto &[l, r] : intervals) std::cin >> l >> r;

    std::pair<long long, long long> sums = {0, 0};
    for (const auto &[l, r] : intervals) {
        sums.first += l;
        sums.second += r;
    }

    if (sums.first > 0 || sums.second < 0) {
        std::cout << "No" << std::endl;
        return 0;
    }

    long long offset = -sums.first;
    std::vector<long long> ans(n);
    for (int i = 0; i < n; i++) {
        if (offset - (intervals[i].second - intervals[i].first) >= 0) {
            ans[i] = intervals[i].second;
            offset -= intervals[i].second - intervals[i].first;
        } else {
            ans[i] = std::min<long long>(offset + intervals[i].first, intervals[i].second);
            offset -= ans[i] - intervals[i].first;
        }
    }
    if (offset == 0) {
        std::cout << "Yes" << std::endl;
        for (const auto &a : ans) std::cout << a << ' ';
        std::cout << std::endl;
        return 0;
    }

    offset = -sums.second;
    for (int i = 0; i < n; i++) {
        if (offset + (intervals[i].first - intervals[i].second) >= 0) {
            ans[i] = intervals[i].first;
            offset += intervals[i].first - intervals[i].second;
        } else {
            ans[i] = std::max<long long>(offset + intervals[i].second, intervals[i].first);
            offset += intervals[i].second - ans[i];
        }
    }
    std::cout << "Yes" << std::endl;
    for (const auto &a : ans) std::cout << a << ' ';
    std::cout << std::endl;
    return 0;
}