#include <iostream>
#include <set>
#include <utility>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    const int NA = q;
    std::set<int> s;
    std::vector<long long> cumsum(q + 1);
    std::vector intervals(n, std::vector<std::pair<int, int>>());

    for (int i = 0; i < q; i++) {
        int x;
        std::cin >> x;
        x--;
        if (!s.contains(x)) {
            s.insert(x);
            intervals[x].push_back({i, NA});
        } else {
            s.erase(x);
            intervals[x].back().second = i;
        }
        cumsum[i + 1] = cumsum[i] + s.size();
    }

    for (int i = 0; i < n; i++) {
        long long a = 0;
        for (const auto &[l, r] : intervals[i]) {
            a += cumsum[r] - cumsum[l];
        }
        std::cout << a << ' ';
    }
    std::cout << std::endl;
    return 0;
}