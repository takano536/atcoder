#include <iostream>
#include <map>

int main() {
    int n;
    std::cin >> n;

    std::map<long long, int> sum, diff;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        sum[static_cast<long long>(i) + a]++;
        diff[static_cast<long long>(i) - a]++;
    }

    long long ans = 0;
    for (const auto &[k, v] : sum) {
        if (!diff.contains(k)) continue;
        ans += static_cast<long long>(v) * diff[k];
    }

    std::cout << ans << std::endl;
    return 0;
}