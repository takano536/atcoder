#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::vector<std::vector<int>> idxes(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
        idxes[a[i]].push_back(i);
    }

    long long ans = 0;
    for (int num = 0; num < n; num++) {
        long long sect_cnt = static_cast<long long>(n + 1) * n / 2;

        int curr = -1;
        idxes[num].push_back(n);
        for (const auto &i : idxes[num]) {
            sect_cnt -= static_cast<long long>(i - curr) * (i - curr - 1) / 2;
            curr = i;
        }

        ans += sect_cnt;
    }

    std::cout << ans << std::endl;
    return 0;
}