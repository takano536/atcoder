#include <algorithm>
#include <iostream>
#include <map>
#include <ranges>
#include <set>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::map<int, std::vector<int>> mod3_idxes, mod5_idxes, mod7_idxes;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        if (a % 3 == 0) mod3_idxes[a / 3].push_back(i);
        if (a % 5 == 0) mod5_idxes[a / 5].push_back(i);
        if (a % 7 == 0) mod7_idxes[a / 7].push_back(i);
    }

    long long ans = 0;
    for (const auto &key : std::views::keys(mod5_idxes)) {
        if (!mod3_idxes.contains(key)) continue;
        if (!mod7_idxes.contains(key)) continue;
        const long long mod3_num = mod3_idxes[key].size();
        const long long mod5_num = mod5_idxes[key].size();
        const long long mod7_num = mod7_idxes[key].size();
        ans += mod3_num * mod5_num * mod7_num;
    }

    for (const auto &[key, idxes] : mod5_idxes) {
        for (const auto &idx : idxes) {
            if (!mod3_idxes.contains(key)) continue;
            if (!mod7_idxes.contains(key)) continue;
            const long long mod3_left_num = std::ranges::lower_bound(mod3_idxes[key], idx) - mod3_idxes[key].begin();
            const long long mod3_right_num = mod3_idxes[key].size() - (std::ranges::lower_bound(mod3_idxes[key], idx) - mod3_idxes[key].begin());
            const long long mod7_left_num = std::ranges::lower_bound(mod7_idxes[key], idx) - mod7_idxes[key].begin();
            const long long mod7_right_num = mod7_idxes[key].size() - (std::ranges::lower_bound(mod7_idxes[key], idx) - mod7_idxes[key].begin());
            ans -= mod3_left_num * mod7_right_num;
            ans -= mod7_left_num * mod3_right_num;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}