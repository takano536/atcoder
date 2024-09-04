#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::pair<int, int>> tests(n);
    for (auto &[a, b] : tests) std::cin >> a >> b;

    std::vector<int> scores;
    for (const auto &[a, b] : tests) {
        scores.push_back(b);
        scores.push_back(a - b);
    }

    std::ranges::sort(scores, std::greater<int>());
    long long ans = 0;
    for (int i = 0; i < k; i++) ans += scores[i];

    std::cout << ans << std::endl;
    return 0;
}