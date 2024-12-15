#include <iostream>

int main() {
    constexpr __int128_t MAX = 1e18;
    int n;
    std::cin >> n;

    bool is_zero = false;
    bool is_overflow = false;

    __int128_t prod = 1;
    for (int _ = 0; _ < n; _++) {
        long long a;
        std::cin >> a;

        if (prod <= MAX) prod *= a;
        if (prod > MAX) is_overflow = true;
        if (a == 0) is_zero = true;
    }

    const long long ans = (is_zero ? 0 : (is_overflow ? -1 : prod));
    std::cout << ans << std::endl;
    return 0;
}