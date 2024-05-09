#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    std::vector<long long> cumsum(n + 1);
    for (int i = 0; i < n; i++) cumsum[i + 1] = cumsum[i] + a[i];

    long long ans = 0;
    for (int i = 0; i < m; i++) {
        ans += static_cast<long long>(a[i]) * (i + 1);
    }

    long long curr = ans;
    for (int i = 1; i <= n - m; i++) {
        curr -= cumsum[i + m - 1] - cumsum[i - 1] - static_cast<long long>(m) * a[i + m - 1];
        ans = std::max(curr, ans);
    }

    std::cout << ans << std::endl;
    return 0;
}