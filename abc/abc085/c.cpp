#include <iostream>

int main() {
    int n, y;
    std::cin >> n >> y;

    const int NA = -1;
    int ans_10k = NA, ans_5k = NA, ans_1k = NA;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n - i; j++) {
            auto k = n - i - j;
            int total = i * 1e4 + j * 5e3 + k * 1e3;
            if (total == y) ans_10k = i, ans_5k = j, ans_1k = k;
        }
    }

    std::cout << ans_10k << ' ' << ans_5k << ' ' << ans_1k << std::endl;
    return 0;
}