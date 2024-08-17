#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    std::vector<long long> cumsum(n * 2 + 1);
    for (int i = 0; i < n * 2; i++) cumsum[i + 1] = (cumsum[i] + a[i % n]) % m;

    long long ans = 0;
    std::vector<int> cnt(m);
    long long offset = 0;
    for (int i = 0; i < n * 2 + 1; i++) {
        cnt[cumsum[i]]++;
        if (i >= n) cnt[cumsum[i - n]]--;
        ans += std::max(0, cnt[cumsum[i]] - 1);
        if (i <= n) offset += cnt[cumsum[i]] - 1;
    }

    std::cout << ans - offset << std::endl;
    return 0;
}