#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    constexpr int CHAR_NUM = 'Z' - 'A' + 1;

    std::string s;
    std::cin >> s;
    int n = s.size();

    std::vector<std::vector<int>> idxes(CHAR_NUM);
    for (int i = 0; i < n; i++) idxes[s[i] - 'A'].push_back(i);
    std::vector<std::vector<int>> rev_idxes(CHAR_NUM);
    for (int i = 0; i < n; i++) rev_idxes[s[i] - 'A'].push_back(-i);
    for (int c = 0; c < CHAR_NUM; c++) std::ranges::sort(rev_idxes[c]);

    long long ans = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int c = 0; c < CHAR_NUM; c++) {
            if (idxes[c].size() < 2) continue;

            int cnt = idxes[c].size();

            auto r_iter = std::ranges::upper_bound(idxes[c], i);
            if (r_iter == idxes[c].end()) continue;
            long long r_dist = cnt - std::distance(idxes[c].begin(), r_iter);

            auto l_iter = std::ranges::upper_bound(rev_idxes[c], -i);
            long long l_dist = cnt - std::distance(rev_idxes[c].begin(), l_iter);

            ans += r_dist * l_dist;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}