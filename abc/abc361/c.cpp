#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    constexpr int INF = 1e9 + 1;
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    std::ranges::sort(a);

    int ans = INF;
    for (int i = 0; i < k + 1; i++) {
        ans = std::min(ans, a[i + n - 1 - k] - a[i]);
    }
    if (ans == INF) ans = 0;

    std::cout << ans << std::endl;
    return 0;
}