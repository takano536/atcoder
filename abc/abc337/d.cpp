#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

int main() {
    const int INF = 1e9;

    int h, w, k;
    std::cin >> h >> w >> k;

    std::vector<std::string> s(h);
    for (int i = 0; i < h; i++) {
        std::cin >> s[i];
    }

    auto count_required_num = [&k, &INF](const std::string &s) -> int {
        int ans = INF;
        int len = s.size();
        std::deque<char> curr;
        int x_cnt = 0;
        int o_cnt = 0;
        for (int i = 0; i < len; i++) {
            curr.push_back(s[i]);
            if (s[i] == 'x') {
                x_cnt++;
            }
            if (s[i] == 'o') {
                o_cnt++;
            }
            if (static_cast<int>(curr.size()) > k) {
                if (curr.front() == 'x') {
                    x_cnt--;
                }
                if (curr.front() == 'o') {
                    o_cnt--;
                }
                curr.pop_front();
            }
            if (x_cnt > 0 || static_cast<int>(curr.size()) < k) {
                continue;
            }
            ans = std::min(ans, static_cast<int>(curr.size()) - o_cnt);
        }
        return ans;
    };

    auto rotate_90 = [](const std::vector<std::string> &s) -> std::vector<std::string> {
        int h = s.size();
        int w = s[0].size();
        std::vector<std::string> ans(w, std::string(h, ' '));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                ans[j][h - i - 1] = s[i][j];
            }
        }
        return ans;
    };

    int ans = INF;
    for (int i = 0; i < h; i++) {
        ans = std::min(ans, count_required_num(s[i]));
    }
    auto rotate_s = rotate_90(s);
    for (int i = 0; i < w; i++) {
        ans = std::min(ans, count_required_num(rotate_s[i]));
    }

    std::cout << (ans == INF ? -1 : ans) << std::endl;
    return 0;
}