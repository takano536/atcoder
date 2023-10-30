#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (auto &in : a) {
        std::cin >> in;
    }

    std::ranges::sort(a);

    int left_idx = 0;
    int right_idx = 0;
    int ans = 1;
    while (right_idx < n - 1) {
        while (a[right_idx] - a[left_idx] < m) {
            right_idx++;
            if (right_idx == n) {
                right_idx--;
                break;
            }
        }
        while (a[right_idx] - a[left_idx] >= m) {
            right_idx--;
        }
        if (left_idx <= right_idx) {
            ans = std::max(ans, right_idx - left_idx + 1);
        }
        left_idx++;
    }

    std::cout << ans << std::endl;
    return 0;
}