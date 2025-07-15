#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<long long> x(n);
    for (auto &xi : x) std::cin >> xi;
    std::ranges::sort(x);

    std::vector<long long> dists(n - 1);
    for (int i = 0; auto &dist : dists) dist = x[i + 1] - x[i], i++;
    std::ranges::sort(dists);

    std::cout << std::accumulate(dists.begin(), std::prev(dists.end(), m - 1), 0LL) << std::endl;
    return 0;
}