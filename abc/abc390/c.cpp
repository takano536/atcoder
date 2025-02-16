#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
    constexpr int NA = -1;

    int h, w;
    std::cin >> h >> w;

    std::vector<std::string> s(h);
    for (auto &si : s) std::cin >> si;

    std::vector<std::pair<int, int>> edges(h);
    int left = NA, right = NA, top = NA, bottom = NA;
    for (int i = 0; i < h; i++) {
        auto &[l, r] = edges[i];
        if (s[i].find('#') == std::string::npos) {
            l = NA;
            r = NA;
        } else {
            l = s[i].find('#');
            r = s[i].rfind('#');
            if (left == NA) left = l;
            left = std::min(left, l);
            right = std::max(right, r);
            if (top == NA) top = i;
        }
    }
    for (int i = h - 1; i >= 0; i--) {
        if (edges[i].first != NA) {
            bottom = i;
            break;
        }
    }

    bool is_satisfied = true;
    for (int i = top; i <= bottom; i++) {
        for (int j = left; j <= right; j++) {
            if (s[i][j] == '.') is_satisfied = false;
        }
    }

    std::cout << (is_satisfied ? "Yes" : "No") << std::endl;
    return 0;
}