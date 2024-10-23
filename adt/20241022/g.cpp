#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#include <atcoder/fenwicktree>

int main() {
    int n, t;
    std::cin >> n >> t;

    std::vector<std::pair<std::pair<long long, int>, int>> ants(n);
    for (auto &[coord, _] : ants) {
        char c;
        std::cin >> c;
        coord.second = (c == '1' ? +1 : -1);
    }
    for (auto &[coord, _] : ants) std::cin >> coord.first;
    std::ranges::sort(ants);
    for (int i = 0; auto &[_, idx] : ants) idx = i++;

    for (auto &[coord, _] : ants) coord.first += t * coord.second;
    std::ranges::sort(ants);

    atcoder::fenwick_tree<int> bit(n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += i - bit.sum(0, ants[i].second);
        bit.add(ants[i].second, 1);
    }

    std::cout << ans << std::endl;
    return 0;
}