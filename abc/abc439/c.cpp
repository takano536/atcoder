#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    constexpr int XY_MAX = 4000;

    int n;
    std::cin >> n;

    std::vector<int> is_good_integers(n + 1);
    for (int x = 1; x <= XY_MAX; x++) {
        for (int y = x + 1; y <= XY_MAX; y++) {
            const auto ret = x * x + y * y;
            if (ret > n) continue;
            is_good_integers[ret]++;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!is_good_integers[i]) continue;
        if (is_good_integers[i] > 1) continue;
        ans++;
    }
    std::cout << ans << std::endl;
    for (int i = 1; i <= n; i++) {
        if (!is_good_integers[i]) continue;
        if (is_good_integers[i] > 1) continue;
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    return 0;
}