#include <iostream>
#include <set>
#include <utility>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> l_limits(m + 1, -1);
    for (int _ = 0; _ < n; _++) {
        int l, r;
        std::cin >> l >> r;
        l_limits[r] = std::max(l, l_limits[r]);
    }

    long long ans = 0;
    int l = 1;
    for (int r = 1; r <= m; r++) {
        l = std::max(l_limits[r] + 1, l);
        ans += r - l + 1;
    }

    std::cout << ans << std::endl;
    return 0;
}