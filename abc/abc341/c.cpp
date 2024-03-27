#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    int h, w, n;
    std::cin >> h >> w >> n;

    std::string t;
    std::cin >> t;

    std::vector<std::string> s(h);
    for (auto &si : s) {
        std::cin >> si;
    }

    const std::map<char, std::pair<int, int>> DIRS = {
        {'L', {0, -1}},
        {'R', {0, 1}},
        {'U', {-1, 0}},
        {'D', {1, 0}},
    };

    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            bool satisfied = true;
            if (s[i][j] == '#') {
                continue;
            }
            auto curr = std::make_pair(i, j);
            for (const auto &c : t) {
                auto next = std::make_pair(curr.first + DIRS.at(c).first, curr.second + DIRS.at(c).second);
                if (next.first < 0 || next.first >= h || next.second < 0 || next.second >= w) {
                    satisfied = false;
                    break;
                }
                if (s[next.first][next.second] == '#') {
                    satisfied = false;
                    break;
                }
                curr = next;
            }
            if (satisfied) {
                ans++;
            }
        }
    }

    std::cout << ans << std::endl;
    return 0;
}