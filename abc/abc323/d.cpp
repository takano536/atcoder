#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> s(n), c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i] >> c[i];
    }

    std::map<long, long> slimes;
    for (int i = 0; i < n; i++) {
        slimes[s[i]] += c[i];
    }

    long ans = 0;
    while (!slimes.empty()) {
        auto [size, cnt] = *slimes.begin();
        slimes.erase(slimes.begin());

        ans += cnt % 2;

        if (cnt < 2) {
            continue;
        }

        slimes[size * 2] += cnt / 2;
    }

    std::cout << ans << std::endl;
    return 0;
}