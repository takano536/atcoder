#include <iostream>
#include <numeric>

int main() {
    long long n, m, k;
    std::cin >> n >> m >> k;

    long long left = 0;
    long long right = std::max(n, m) * k + 1;

    while (right - left > 1) {
        long long mid_base = (left + right) / 2;
        long long mid_n = (mid_base / n) * n;
        long long mid_m = (mid_base / m) * m;
        long long mid = (mid_n > mid_m ? mid_n : mid_m);
        long long n_cnt = mid / n - mid / std::lcm(n, m);
        long long m_cnt = mid / m - mid / std::lcm(n, m);
        (n_cnt + m_cnt < k ? left : right) = mid_base;
    }

    std::cout << right << std::endl;
    return 0;
}