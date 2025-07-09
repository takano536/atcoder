#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> x(n);
    for (int i = 0; auto &[xi, index] : x) std::cin >> xi, index = i++;

    auto sorted_x = x;
    std::ranges::sort(sorted_x);

    std::vector<int> ans(n);
    for (int index = 0; const auto &[xi, i] : sorted_x) ans[i] = sorted_x[index++ < n / 2 ? n / 2 : n / 2 - 1].first;

    for (const auto &median : ans) std::cout << median << '\n';
    std::cout << std::flush;

    return 0;
}