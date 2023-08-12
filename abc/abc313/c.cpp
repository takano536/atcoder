#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    for (auto &input : a) {
        std::cin >> input;
    }
    std::sort(a.rbegin(), a.rend());

    long long ans = 0;
    long long sum = std::accumulate(a.begin(), a.end(), 0LL);
    auto final_a = static_cast<long long>(std::floor(static_cast<long double>(sum) / n));
    long long cnt = sum - final_a * n;
    for (int i = 0; i < n; i++) {
        if (a[i] <= final_a + 1) {
            continue;
        }
        auto goal = final_a + (cnt > 0 ? 1 : 0);
        cnt--;
        ans += a[i] - goal;
    }

    std::cout << ans << std::endl;
}