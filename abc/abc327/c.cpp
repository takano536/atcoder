#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

int main() {
    int N = 9;
    std::vector<std::vector<int>> a(N, std::vector<int>(N));
    for (auto &vec : a) {
        for (auto &in : vec) {
            std::cin >> in;
            in--;
        }
    }

    bool satisfies = true;
    for (int i = 0; i < N; i++) {
        std::vector<bool> used(N);
        for (int j = 0; j < N; j++) {
            used[a[i][j]] = true;
        }
        if (!std::ranges::all_of(used, [](int x) { return x; })) {
            satisfies = false;
        }
    }
    for (int i = 0; i < N; i++) {
        std::vector<bool> used(N);
        for (int j = 0; j < N; j++) {
            used[a[j][i]] = true;
        }
        if (!std::ranges::all_of(used, [](int x) { return x; })) {
            satisfies = false;
        }
    }
    for (int i = 0; i < N; i += 3) {
        for (int j = 0; j < N; j += 3) {
            std::vector<bool> used(N);
            for (int ii = 0; ii < 3; ii++) {
                for (int jj = 0; jj < 3; jj++) {
                    used[a[i + ii][j + jj]] = true;
                }
            }
            if (!std::ranges::all_of(used, [](int x) { return x; })) {
                satisfies = false;
            }
        }
    }

    std::cout << (satisfies ? "Yes" : "No") << std::endl;
    return 0;
}