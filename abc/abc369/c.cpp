#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    if (n == 1) {
        std::cout << 1 << std::endl;
        return 0;
    }
    if (n == 2) {
        std::cout << 3 << std::endl;
        return 0;
    }

    long long ans = 3;
    int left = 0;
    int right = 1;
    int d = a[right] - a[left];
    while (right < n - 1) {
        if (right < n - 1) right++;
        if (a[right] - a[right - 1] != d) {
            left = right - 1;
            d = a[right] - a[left];
        }
        ans += right - left + 1;
    }

    std::cout << ans << std::endl;
    return 0;
}