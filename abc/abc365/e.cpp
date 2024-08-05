#include <iostream>
#include <numeric>
#include <vector>

int main() {
    constexpr int MAX_BIT = 30;

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    std::vector<int> cumxor(n + 1);
    for (int i = 0; i < n; i++) cumxor[i + 1] = cumxor[i] ^ a[i];

    std::vector<int> bitcnts(MAX_BIT);
    for (const auto &num : cumxor) {
        for (int i = 0; i < MAX_BIT; i++) {
            bitcnts[i] += (num & (1 << i) ? 1 : 0);
        }
    }

    long long ans = 0;
    for (int i = 0; i < MAX_BIT; i++) {
        ans += static_cast<long long>(bitcnts[i]) * (cumxor.size() - bitcnts[i]) * (1 << i);
    }
    ans -= std::accumulate(a.begin(), a.end(), 0LL);

    std::cout << ans << std::endl;
    return 0;
}