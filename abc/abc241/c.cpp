#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> s(n);
    for (auto &si : s) {
        std::cin >> si;
    }

    const int LEN = 6;
    const int PAINT_NUM = 2;
    bool is_satisfied = false;
    const std::vector<std::pair<int, int>> DIRS = {{0, 1}, {1, 1}, {1, 0}, {-1, 1}};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (const auto &dir : DIRS) {
                int curr_i = i;
                int curr_j = j;
                int cnt = 0;
                bool is_line = true;
                for (int k = 0; k < LEN; k++) {
                    if (curr_i < 0 || curr_i >= n || curr_j < 0 || curr_j >= n) {
                        is_line = false;
                        break;
                    }
                    if (s[curr_i][curr_j] == '.') {
                        cnt++;
                    }
                    curr_i += dir.first, curr_j += dir.second;
                }
                is_line &= cnt <= PAINT_NUM;
                is_satisfied |= is_line;
            }
        }
    }
    std::cout << (is_satisfied ? "Yes" : "No") << std::endl;
    return 0;
}