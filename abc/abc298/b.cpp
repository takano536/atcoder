#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<int>> rotate(const std::vector<std::vector<int>> &matrix) {
    int n = matrix[0].size();
    auto ret = matrix;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ret[i][j] = matrix[n - 1 - j][i];
        }
    }
    return ret;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> a(n, std::vector<int>(n)), b(n, std::vector<int>(n));
    for (auto &vec : a) {
        for (auto &num : vec)
            std::cin >> num;
    }
    for (auto &vec : b) {
        for (auto &num : vec)
            std::cin >> num;
    }

    bool satisfies = false;
    for (int i = 0; i < 4; i++) {
        a = rotate(a);
        bool is_ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 1 && a[i][j] != b[i][j]) {
                    is_ok = false;
                }
            }
        }
        if (is_ok) {
            satisfies = true;
        }
    }

    std::cout << (satisfies ? "Yes" : "No") << std::endl;
}