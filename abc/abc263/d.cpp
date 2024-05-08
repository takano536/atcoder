#include <iostream>
#include <vector>

int main() {
    int n, l, r;
    std::cin >> n >> l >> r;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    long long ans = static_cast<long long>(r) * n;
    long long a_sum = 0;
    long long diff_sum = 0;
    long long max_diff_sum = 0;
    for (int i = 0; i < n; i++) {
        a_sum += a[i];
        diff_sum += static_cast<long long>(a[i]) - l;
        max_diff_sum = std::max(diff_sum, max_diff_sum);
        ans = std::min(static_cast<long long>(r) * (n - i - 1) + a_sum - max_diff_sum, ans);
    }

    std::cout << ans << std::endl;
    return 0;
}