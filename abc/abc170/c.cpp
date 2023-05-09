#include <algorithm>
#include <iostream>
#include <set>

int main() {
    int x, n;
    std::cin >> x >> n;

    std::set<int> p;
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        p.insert(num);
    }

    std::pair<int, int> ans = {1e9, 1e9};
    for (int i = 0; i <= 101; i++) {
        if (p.find(i) != p.end()) {
            continue;
        }

        if (ans.second < std::abs(i - x)) {
            continue;
        }
        if (ans.second == std::abs(i - x) && ans.first < i) {
            continue;
        }

        ans = {i, abs(i - x)};
    }

    std::cout << ans.first << std::endl;
}