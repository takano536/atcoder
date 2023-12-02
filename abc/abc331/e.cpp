#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
    int n, m, l;
    std::cin >> n >> m >> l;

    std::vector<std::pair<int, int>> a(n), b(m);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i].first;
        b[i].second = i;
    }

    std::ranges::sort(a, std::greater<std::pair<int, int>>());
    std::ranges::sort(b, std::greater<std::pair<int, int>>());

    std::set<std::pair<int, int>> bad_pairs;
    for (int i = 0; i < l; i++) {
        int c, d;
        std::cin >> c >> d;
        c--, d--;
        bad_pairs.emplace(c, d);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!bad_pairs.contains({a[i].second, b[j].second})) {
                ans = std::max(ans, static_cast<long long>(a[i].first) + b[j].first);
                break;
            }
        }
    }

    std::cout << ans << std::endl;
    return 0;
}