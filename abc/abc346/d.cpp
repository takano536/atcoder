#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<long long> c(n);
    for (auto &ci : c) {
        std::cin >> ci;
    }

    std::vector<std::pair<long long, long long>> cost_cumsum(n + 1);  // first: zero, second:one
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            cost_cumsum[i + 1].first = cost_cumsum[i].first + (s[i] == '0' ? c[i] : 0);
            cost_cumsum[i + 1].second = cost_cumsum[i].second + (s[i] == '1' ? c[i] : 0);
        } else {
            cost_cumsum[i + 1].first = cost_cumsum[i].first + (s[i] == '1' ? c[i] : 0);
            cost_cumsum[i + 1].second = cost_cumsum[i].second + (s[i] == '0' ? c[i] : 0);
        }
    }

    long long ans = 1e18;
    for (int i = 0; i < n - 1; i++) {
        long long cost_zero = 0;
        cost_zero += s[i] == '1' ? c[i] : 0;
        cost_zero += s[i + 1] == '1' ? c[i + 1] : 0;
        if (i + 2 < n) {
            cost_zero += (i + 2) % 2 ? cost_cumsum[n].first - cost_cumsum[i + 2].first : cost_cumsum[n].second - cost_cumsum[i + 2].second;
        }
        if (i - 1 >= 0) {
            cost_zero += (i - 1) % 2 ? cost_cumsum[i].first - cost_cumsum[0].first : cost_cumsum[i].second - cost_cumsum[0].second;
        }

        long long cost_one = 0;
        cost_one += s[i] == '0' ? c[i] : 0;
        cost_one += s[i + 1] == '0' ? c[i + 1] : 0;
        if (i + 2 < n) {
            cost_one += (i + 2) % 2 ? cost_cumsum[n].second - cost_cumsum[i + 2].second : cost_cumsum[n].first - cost_cumsum[i + 2].first;
        }
        if (i - 1 >= 0) {
            cost_one += (i - 1) % 2 ? cost_cumsum[i].second - cost_cumsum[0].second : cost_cumsum[i].first - cost_cumsum[0].first;
        }
        ans = std::min(ans, std::min(cost_zero, cost_one));
    }

    std::cout << ans << std::endl;
}