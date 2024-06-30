#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include <atcoder/fenwicktree>

int main() {
    int n, t;
    std::cin >> n >> t;

    std::string s;
    std::cin >> s;

    std::vector<std::pair<long long, int>> x(n);
    for (auto &xi : x) std::cin >> xi.first;

    for (int i = 0; i < n; i++) x[i].second = (s[i] == '1' ? t : -t);
    std::ranges::sort(x);

    std::vector<long long> added_x(n);
    for (int i = 0; i < n; i++) {
        added_x[i] = x[i].first + x[i].second;
    }

    std::vector<long long> unique_x = added_x;
    std::ranges::sort(unique_x);
    unique_x.erase(std::unique(unique_x.begin(), unique_x.end()), unique_x.end());

    std::vector<int> commpressed_x(n);
    for (int i = 0; i < n; i++) {
        commpressed_x[i] = std::ranges::lower_bound(unique_x, added_x[i]) - unique_x.begin();
    }

    long long ans = 0;
    atcoder::fenwick_tree<int> bit(n);
    for (int i = 0; i < n; i++) {
        ans += i - bit.sum(0, commpressed_x[i]);
        bit.add(commpressed_x[i], 1);
    }

    std::cout << ans << std::endl;
    return 0;
}