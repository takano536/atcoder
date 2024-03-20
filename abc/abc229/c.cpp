#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    int n, w;
    std::cin >> n >> w;
    std::vector<std::pair<int, int>> cheeses(n);
    for (auto &[a, b] : cheeses) {
        std::cin >> a >> b;
    }
    std::ranges::sort(cheeses, std::greater<std::pair<int, int>>());

    long long ans = 0;
    int curr_w = w;
    for (const auto &[a, b] : cheeses) {
        long long used_cheese = std::min(b, curr_w);
        ans += used_cheese * a;
        curr_w -= b;
        if (curr_w <= 0) {
            break;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}