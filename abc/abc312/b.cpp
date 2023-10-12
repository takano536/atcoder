#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    for (auto &si : s) {
        std::cin >> si;
    }

    std::vector<std::pair<int, int>> ans;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool satisfied = true;
            for (int ii = 0; ii < 3; ii++) {
                if (!satisfied) {
                    break;
                }
                for (int jj = 0; jj < 3; jj++) {
                    if (i + ii >= n || j + jj >= m) {
                        satisfied = false;
                        break;
                    }
                    if (s[i + ii][j + jj] != '#') {
                        satisfied = false;
                        break;
                    }
                }
            }
            for (int ii = 0; ii < 3; ii++) {
                if (!satisfied) {
                    break;
                }
                for (int jj = 0; jj < 3; jj++) {
                    if (i + ii + 6 >= n || j + jj + 6 >= m) {
                        satisfied = false;
                        break;
                    }
                    if (s[i + ii + 6][j + jj + 6] != '#') {
                        satisfied = false;
                        break;
                    }
                }
            }

            for (int ii = 0; ii < 4; ii++) {
                if (i + ii >= n || j + 3 >= m) {
                    satisfied = false;
                    break;
                }
                if (s[i + ii][j + 3] != '.') {
                    satisfied = false;
                    break;
                }
            }
            for (int jj = 0; jj < 4; jj++) {
                if (i + 3 >= n || j + jj >= m) {
                    satisfied = false;
                    break;
                }
                if (s[i + 3][j + jj] != '.') {
                    satisfied = false;
                    break;
                }
            }
            if (satisfied) {
                ans.emplace_back(i + 1, j + 1);
            }
        }
    }

    for (const auto &p : ans) {
        std::cout << p.first << " " << p.second << std::endl;
    }
    return 0;
}