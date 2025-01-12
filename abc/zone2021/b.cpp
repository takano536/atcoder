#include <iomanip>
#include <iostream>

int main() {
    constexpr int INF = 1e9;

    int n, d, h;
    std::cin >> n >> d >> h;

    double min_slope = INF;
    for (int i = 0; i < n; i++) {
        int di, hi;
        std::cin >> di >> hi;
        min_slope = std::min(static_cast<double>(h - hi) / (d - di), min_slope);
    }

    std::cout << std::fixed << std::setprecision(9) << std::max(0.0, min_slope * -d + h) << std::endl;
    return 0;
}