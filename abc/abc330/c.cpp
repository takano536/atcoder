#include <cmath>
#include <iostream>

int main() {
    long long d;
    std::cin >> d;

    long long ans = 1e18;
    for (long long x = 0; x <= 1e7; x++) {
        long long diff = x * x - d;

        long long left = 0;
        long long right = 1e7;
        while (right - left > 1) {
            long long mid = (left + right) / 2;
            if (diff + mid * mid > 0) {
                right = mid;
            } else {
                left = mid;
            }
        }
        ans = std::min(ans, std::min(std::abs(diff + left * left), std::abs(diff + right * right)));
    }
    std::cout << ans << std::endl;
}