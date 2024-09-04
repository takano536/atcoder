#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
    constexpr int CHAR_NUM = 'z' - 'a' + 1;
    constexpr int NA = -1;

    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    std::vector<std::set<int>> idxes(CHAR_NUM);
    for (int i = 0; i < n; i++) idxes[s[i] - 'a'].insert(i);

    std::vector next_idx(n, std::vector<int>(CHAR_NUM, NA));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < CHAR_NUM; j++) {
            auto idx = idxes[j].lower_bound(i);
            if (idx == idxes[j].end()) continue;
            next_idx[i][j] = *idx;
        }
    }

    std::string ans;
    int curr_idx = 0;
    for (int i = 0; i < k; i++) {
        for (int chr = 0; chr < CHAR_NUM; chr++) {
            if (next_idx[curr_idx][chr] == NA) continue;
            if (n - next_idx[curr_idx][chr] <= k - i - 1) continue;
            ans += s[next_idx[curr_idx][chr]];
            curr_idx = next_idx[curr_idx][chr] + 1;
            break;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}