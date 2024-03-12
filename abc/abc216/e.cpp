#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<long long> a(n);
    for (auto &ai : a) {
        std::cin >> ai;
    }

    k = std::min(static_cast<long long>(k), std::accumulate(a.begin(), a.end(), 0LL));
    std::ranges::sort(a, std::ranges::greater());

    long long left = 1;
    long long right = *std::ranges::max_element(a) + 1;
    while (right - left > 1) {
        const auto mid = (left + right) / 2;
        long long cnt = 0;
        for (const auto &ai : a) {
            cnt += std::max(ai - mid + 1, 0LL);
        }
        (cnt > k ? left : right) = mid;
    }

    long long cnt = 0;
    long long ans = 0;
    for (auto &ai : a) {
        if (ai < right) {
            continue;
        }
        ans += ai * (ai + 1) / 2 - (right - 1) * right / 2;
        cnt += ai - right + 1;
    }
    ans += left * std::max(0LL, k - cnt);
    std::cout << ans << std::endl;
    return 0;
}