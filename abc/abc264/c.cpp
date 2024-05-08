#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int h1, w1;
    std::cin >> h1 >> w1;

    std::vector a(h1, std::vector<int>(w1));
    for (int i = 0; i < h1; i++) {
        for (int j = 0; j < w1; j++) std::cin >> a[i][j];
    }

    int h2, w2;
    std::cin >> h2 >> w2;

    std::vector b(h2, std::vector<int>(w2));
    for (int i = 0; i < h2; i++) {
        for (int j = 0; j < w2; j++) std::cin >> b[i][j];
    }

    const int n = h1 + w1;
    bool is_satisfied = false;
    for (int bit = 0; bit < (1 << n); bit++) {
        auto matrix = a;

        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) continue;

            if (i < h1) {
                std::ranges::fill(matrix[i], 0);
            } else {
                auto j = i - h1;
                for (std::size_t k = 0; k < matrix.size(); k++) matrix[k][j] = 0;
            }
        }

        for (auto iter = matrix.begin(); iter != matrix.end();) {
            if (std::ranges::all_of(*iter, [](int x) { return x == 0; })) {
                iter = matrix.erase(iter);
            } else {
                iter++;
            }
        }
        for (auto &v : matrix) {
            for (auto iter = v.begin(); iter != v.end();) {
                *iter == 0 ? iter = v.erase(iter) : iter++;
            }
        }

        if (matrix.size() == 0 || matrix.size() != b.size() || matrix[0].size() != b[0].size()) {
            continue;
        }

        bool is_same = true;
        for (int i = 0; i < h2; i++) {
            for (int j = 0; j < w2; j++) {
                if (matrix[i][j] != b[i][j]) is_same = false;
            }
        }

        if (is_same) is_satisfied = true;
    }

    std::cout << (is_satisfied ? "Yes" : "No") << std::endl;
    return 0;
}