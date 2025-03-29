#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

int solve(const std::vector<int> &a) {
    const int n = a.size();
    std::map<int, std::set<std::pair<int, int>>> idxes;
    std::set<int> bad_pairs;
    for (int i = 0; i < n; i++) {
        if (i - 1 >= 0 && a[i] == a[i - 1]) bad_pairs.insert(a[i]);
        if (i + 1 < n && a[i] == a[i + 1]) bad_pairs.insert(a[i]);
        if (i - 1 >= 0) idxes[a[i]].insert({a[i - 1], i - 1});
        if (i + 1 < n) idxes[a[i]].insert({a[i + 1], i + 1});
    }

    std::set<std::pair<int, int>> pairs;
    std::set<std::pair<int, int>> ans;
    for (const auto &[a, v] : idxes) {
        if (bad_pairs.contains(a)) continue;
        std::map<int, int> cnt;
        for (auto &[b, _] : v) cnt[b]++;
        for (const auto &[b, c] : cnt) {
            if (bad_pairs.contains(b)) continue;
            auto pair = std::make_pair(std::min(a, b), std::max(a, b));
            if (c < 2 || b == a) continue;
            if (pairs.contains(pair)) ans.insert(pair);
            if (c >= 2 && b != a) pairs.insert(pair);
        }
    }

    return ans.size();
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n * 2);
        for (auto &ai : a) std::cin >> ai;
        std::cout << solve(a) << std::endl;
    }
    return 0;
}