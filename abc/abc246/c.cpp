#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    int n, k, x;
    std::cin >> n >> k >> x;
    std::vector<int> a(n);
    for (auto &ai : a) {
        std::cin >> ai;
    }

    int cnt = 0;
    for (auto &ai : a) {
        if (cnt + ai / x >= k) {
            ai -= (k - cnt) * x;
            cnt = k;
            break;
        }
        cnt += ai / x;
        ai -= (ai / x) * x;
    }
    if (cnt == k) {
        std::cout << std::accumulate(a.begin(), a.end(), 0LL) << std::endl;
        return 0;
    }

    std::ranges::sort(a, std::greater<int>());
    for (auto &ai : a) {
        if (cnt + std::max(1, ai / x) >= k) {
            ai = std::max(0, ai - std::max(1, ai / x) * x);
            cnt = k;
            break;
        }
        cnt += std::max(1, ai / x);
        ai = std::max(0, ai - std::max(1, ai / x) * x);
    }
    std::cout << std::accumulate(a.begin(), a.end(), 0LL) << std::endl;
    return 0;
}
