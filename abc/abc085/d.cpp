#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

bool compare_by_second(std::pair<int, int> a, std::pair<int, int> b) {
    if (a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int main() {
    int n, h;
    std::cin >> n >> h;

    std::vector<std::pair<int, int>> katanas(n);
    for (auto &katana : katanas) {
        std::cin >> katana.first >> katana.second;
    }

    auto swing_katana = *std::max_element(katanas.begin(), katanas.end());

    std::vector<std::pair<int, int>> throw_katanas;
    for (const auto &katana : katanas) {
        if (katana.second > swing_katana.first) {
            throw_katanas.push_back(katana);
        }
    }
    std::sort(throw_katanas.rbegin(), throw_katanas.rend(), compare_by_second);

    int ans = 0;
    for (const auto &katana : throw_katanas) {
        h -= katana.second;
        ans++;
        if (h <= 0) {
            std::cout << ans << std::endl;
            return 0;
        }
    }
    ans += std::ceil(static_cast<double>(h) / swing_katana.first);

    std::cout << ans << std::endl;
    return 0;
}