#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

int main() {
    long long n;
    int m;
    std::cin >> n >> m;

    std::vector<std::tuple<long long, long long, long long>> conditions(m);
    for (auto &[diff, a, b] : conditions) {
        std::cin >> a >> b;
        diff = a - b;
    }

    std::ranges::sort(conditions);

    long long ans = 0;
    for (const auto &[diff, a, b] : conditions) {
        if (n - a < 0) continue;
        const auto count = (n - a) / diff + 1;
        ans += count;
        n -= diff * count;
    }

    std::cout << ans << std::endl;
    return 0;
}