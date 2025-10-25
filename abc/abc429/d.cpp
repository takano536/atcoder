#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>

int main() {
    int n, c;
    long long m;
    std::cin >> n >> m >> c;

    std::map<long long, int> counts;
    std::vector<long long> a(n * 2);
    counts[0] = 0;
    counts[m - 1] = 0;
    counts[m] = 0;

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i + n] = a[i] + m;
        counts[a[i]]++, counts[a[i] + m]++;
    }

    std::vector<long long> coords(counts.size());
    int i = 0;
    for (auto iter = counts.begin(); iter != counts.end(); iter++) {
        coords[i] = iter->first;
        i++;
    }

    std::vector<long long> cumsum = {counts.begin()->second};
    for (auto iter = std::next(counts.begin()); iter != counts.end(); iter++) {
        cumsum.push_back(cumsum.back() + iter->second);
    }

    long long ans = 0;
    i = 1;
    auto counts_iter = counts.begin();
    auto cumsum_iter = cumsum.begin();
    while (counts_iter->first < m) {
        const auto [coord, count] = *std::next(counts_iter);
        long long xi = count;
        if (xi < c) {
            const long long offset = cumsum[i] + c - xi;
            const auto stop_iter = std::ranges::lower_bound(cumsum, offset);
            xi += *stop_iter - cumsum[i];
        }
        const auto dist = coords[i] - coords[i - 1];
        ans += xi * dist;
        i++, counts_iter++, cumsum_iter++;
    }

    std::cout << ans << std::endl;
    return 0;
}