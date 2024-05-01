#include <iostream>
#include <vector>

int main() {
    std::vector<int> intervals(3e5);

    int n;
    std::cin >> n;
    int max_right = 0;
    for (int i = 0; i < n; i++) {
        int l, r;
        std::cin >> l >> r;
        max_right = std::max(r, max_right);
        l--, r--;
        intervals[l]++;
        intervals[r]--;
    }

    const int NA = -1;
    int left = (intervals[0] > 0 ? 0 : NA);
    int right = NA;
    for (int i = 0; i <= max_right; i++) {
        intervals[i + 1] += intervals[i];
        if (left == NA && intervals[i + 1] > 0) {
            left = i + 1;
        }
        if (left != NA && right == NA && intervals[i + 1] <= 0) {
            right = i + 1;
        }
        if (left != NA && right != NA) {
            std::cout << left + 1 << ' ' << right + 1 << std::endl;
            left = NA, right = NA;
        }
    }

    return 0;
}