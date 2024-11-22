#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int &ai : a) std::cin >> ai;

    auto rle = [](const std::vector<int> &v) {
        std::vector<std::pair<int, int>> res;
        for (const int &x : v) {
            if (res.empty() || res.back().first != x) {
                res.emplace_back(x, 1);
                continue;
            }
            res.back().second++;
        }
        return res;
    };

    auto encoded_a = rle(a);
    auto iter = encoded_a.begin();
    while (iter != encoded_a.end()) {
        if (iter->second >= 2) break;
        iter++;
    }

    if (iter == encoded_a.end()) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::set<int> used_nums;
    used_nums.insert(iter->first);
    int ans = 2;
    int max_len = 2;
    std::size_t head = std::distance(encoded_a.begin(), iter);
    std::size_t tail = head;
    while (head < encoded_a.size()) {
        head++;
        if (encoded_a[head].second < 2) {
            head++;
            tail = head;
            used_nums.clear();

            if (head >= encoded_a.size()) break;

            max_len = encoded_a[head].second >= 2 ? 2 : 0;
            if (encoded_a[head].second >= 2) used_nums.insert(encoded_a[head].first);

            continue;
        }

        max_len += 2;
        while (tail < head && used_nums.contains(encoded_a[head].first)) {
            used_nums.erase(encoded_a[tail].first);
            max_len -= 2;
            tail++;
        }

        used_nums.insert(encoded_a[head].first);
        ans = std::max(max_len, ans);

        if (encoded_a[head].second > 2) {
            tail = head;
            max_len = 2;
            used_nums.clear();
            used_nums.insert(encoded_a[head].first);
        }
    }

    std::cout << ans << std::endl;
    return 0;
}