#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector a(m, std::set<int>());
    std::vector<bool> has_opened(n);
    for (int i = 0; i < m; i++) {
        int c;
        std::cin >> c;
        for (int j = 0; j < c; j++) {
            int id;
            std::cin >> id;
            a[i].insert(id - 1);
        }
        char r;
        std::cin >> r;
        has_opened[i] = (r == 'o' ? true : false);
    }

    int ans = 0;
    for (int bit = 0; bit < (1 << n); bit++) {
        std::set<int> ids;
        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) ids.insert(i);
        }

        bool is_satisfied = true;
        for (int i = 0; i < m; i++) {
            auto intersection = std::set<int>();
            std::set_intersection(
                a[i].begin(), a[i].end(),
                ids.begin(), ids.end(),
                std::inserter(intersection, intersection.begin())
            );
            if (intersection.size() >= static_cast<std::size_t>(k) && !has_opened[i]) {
                is_satisfied = false;
                break;
            }
            if (intersection.size() < static_cast<std::size_t>(k) && has_opened[i]) {
                is_satisfied = false;
                break;
            }
        }
        ans += (is_satisfied ? 1 : 0);
    }

    std::cout << ans << std::endl;
    return 0;
}