#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::pair<int, int>> cnts(n);
    long long total = 0;
    for (auto &input : cnts) {
        std::cin >> input.first >> input.second;
        total += input.second;
    }

    std::sort(cnts.begin(), cnts.end());

    int ans = 1;
    if (total <= k) {
        std::cout << ans << std::endl;
        return 0;
    }

    for (const auto &cnt : cnts) {
        total -= cnt.second;
        ans = cnt.first + 1;
        if (total <= k) {
            break;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}