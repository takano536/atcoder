#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> p(n);
    for (auto &pi : p) std::cin >> pi;

    std::vector<int> mounts, valleys;
    for (int i = 0; i < n; i++) {
        if (i + 2 < n && p[i] > p[i + 1] && p[i + 1] < p[i + 2]) {
            valleys.push_back(i + 1);
        } else if (i + 2 < n && p[i] < p[i + 1] && p[i + 1] > p[i + 2]) {
            mounts.push_back(i + 1);
        }
    }

    long long ans = 0;
    for (const auto &mount : mounts) {
        auto valley_iter = std::ranges::lower_bound(valleys, mount);
        if (valley_iter == valleys.end()) continue;

        long long mount_count = 0;
        for (int i = mount - 1; i >= 0; i--) {
            if (*valley_iter + 1 - i + 1 >= 4) mount_count++;
            if (i - 1 >= 0 && p[i] < p[i - 1]) break;
        }

        for (int i = *valley_iter + 1; i < n; i++) {
            ans += mount_count;
            if (i + 1 < n && p[i] > p[i + 1]) break;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}