#include <iostream>
#include <utility>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> heights(n);
    long long total_a = 0;
    for (auto &[a, b] : heights) {
        std::cin >> a >> b;
        total_a += a;
    }

    long long ans = 0;
    for (auto &[a, b] : heights) {
        ans = std::max(ans, total_a - a + b);
    }

    std::cout << ans << std::endl;
    return 0;
}