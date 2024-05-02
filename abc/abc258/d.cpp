#include <iostream>
#include <vector>

int main() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i];
    }

    std::vector<long long> a_cumsum(n + 1), b_cumsum(n + 1);
    for (int i = 0; i < n; i++) {
        a_cumsum[i + 1] = a_cumsum[i] + a[i];
        b_cumsum[i + 1] = b_cumsum[i] + b[i];
    }

    long long ans = 8e18;
    for (int i = 0; i < std::min(n, x); i++) {
        long long time = a_cumsum[i + 1] + b_cumsum[i];
        time += static_cast<long long>(b[i]) * (x - i);
        ans = std::min(time, ans);
    }

    std::cout << ans << std::endl;
    return 0;
}