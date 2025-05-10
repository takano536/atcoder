#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    std::vector<long long> cumsum(n + 1);
    for (int i = 0; i < n; i++) cumsum[i + 1] = cumsum[i] + a[i];

    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += a[i] * (cumsum[n] - cumsum[i + 1]);
    }

    std::cout << ans << std::endl;
    return 0;
}