#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first;
        a[i].second = i;
    }

    std::sort(a.begin(), a.end());
    auto max_abs = std::abs(a[0].first) > std::abs(a[n - 1].first) ? a[0] : a[n - 1];

    std::vector<std::pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        if (i == max_abs.second) {
            continue;
        }
        ans.push_back({max_abs.second, i});
    }

    if (max_abs.first > 0) {
        for (int i = 0; i < n - 1; i++) {
            ans.push_back({i, i + 1});
        }
    } else {
        for (int i = n - 1; i > 0; i--) {
            ans.push_back({i, i - 1});
        }
    }

    std::cout << ans.size() << std::endl;
    for (const auto &[x, y] : ans) {
        std::cout << x + 1 << ' ' << y + 1 << std::endl;
    }
    return 0;
}