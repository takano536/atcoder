#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (auto &ai : a) {
        std::cin >> ai;
    }

    if (k == 1) {
        std::cout << "Yes" << std::endl;
        return 0;
    }

    std::vector sub_a(k, std::vector<int>());
    for (int i = 0; const auto &ai : a) {
        sub_a[i++ % k].push_back(ai);
    }
    for (auto &sub_ai : sub_a) {
        std::ranges::sort(sub_ai);
    }

    int prev = sub_a[0][0];
    bool is_satisfied = true;
    for (int i = 0; i < n; i++) {
        if (prev > sub_a[i % k][i / k]) {
            is_satisfied = false;
        }
        prev = sub_a[i % k][i / k];
    }

    std::cout << (is_satisfied ? "Yes" : "No") << std::endl;
    return 0;
}