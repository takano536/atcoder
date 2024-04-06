#include <iostream>
#include <map>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::map<int, int> metrics;
    for (int i = 0; i < n; i++) {
        int a, c;
        std::cin >> a >> c;
        metrics[c] = metrics.contains(c) ? std::min(metrics[c], a) : a;
    }
    int ans = 0;
    for (const auto metrix : metrics) {
        ans = std::max(ans, metrix.second);
    }
    std::cout << ans << std::endl;
    return 0;
}