#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<double> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i];
    }
    const int LEN = std::accumulate(a.begin(), a.end(), 0);

    const double EPS = 1e-7;
    double left = 0;
    double right = LEN;
    while (std::abs(right - left) > EPS) {
        auto mid = (right + left) / 2;
        double left_time = 0;
        double right_time = 0;

        double curr_pos = 0;
        double dist = mid;
        for (int i = 0; i < n; i++) {
            curr_pos += a[i];
            left_time += (curr_pos <= dist ? a[i] : a[i] - std::abs(curr_pos - dist)) / b[i];
            if (curr_pos >= dist) {
                break;
            }
        }

        curr_pos = 0;
        dist = LEN - mid;
        for (int i = n - 1; i >= 0; i--) {
            curr_pos += a[i];
            right_time += (curr_pos <= dist ? a[i] : a[i] - std::abs(curr_pos - dist)) / b[i];
            if (curr_pos >= dist) {
                break;
            }
        }
        (left_time < right_time ? left : right) = mid;
    }

    std::cout << std::setprecision(7) << left << std::endl;
    return 0;
}