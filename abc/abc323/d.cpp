#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> s(n), c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i] >> c[i];
    }

    std::set<std::pair<long long, long long>> que;
    for (int i = 0; i < n; i++) {
        que.insert(std::make_pair(s[i], c[i]));
    }

    long long ans = 0;
    while (que.size() > 0) {
        auto [size, cnt] = *que.begin();
        que.erase(que.begin());

        ans += cnt % 2;

        if (cnt == 1) {
            continue;
        }

        auto next = que.lower_bound(std::make_pair(size * 2, 0));
        if (next->first != size * 2) {
            que.insert(std::make_pair(size * 2, static_cast<long long>(cnt / 2)));
            continue;
        }
        que.erase(next);
        que.insert(std::make_pair(size * 2, static_cast<long long>(cnt / 2) + next->second));
    }

    std::cout << ans << std::endl;
    return 0;
}