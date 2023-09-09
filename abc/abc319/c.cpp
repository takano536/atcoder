#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> c(9);
    for (int i = 0; i < 9; i++) {
        std::cin >> c[i];
    }

    auto search_row = [&](const std::vector<int> &v) {
        bool is_sad = false;
        for (int i = 0; i < 3; i++) {
            if (is_sad) {
                break;
            }
            std::vector<std::pair<int, int>> nums;
            for (int j = 0; j < 9; j++) {
                if (j == i * 3 || j == i * 3 + 1 || j == i * 3 + 2) {
                    nums.emplace_back(v[j], c[j]);
                }
            }
            std::sort(nums.begin(), nums.end());
            is_sad = nums[0].second == nums[1].second;
        }
        return is_sad;
    };
    auto search_column = [&](const std::vector<int> &v) {
        bool is_sad = false;
        for (int i = 0; i < 3; i++) {
            if (is_sad) {
                break;
            }
            std::vector<std::pair<int, int>> nums;
            for (int j = 0; j < 9; j++) {
                if (j % 3 == i) {
                    nums.emplace_back(v[j], c[j]);
                }
            }
            std::sort(nums.begin(), nums.end());
            is_sad = nums[0].second == nums[1].second;
        }
        return is_sad;
    };
    auto search_diagonal = [&](const std::vector<int> &v) {
        bool is_sad = false;
        {
            std::vector<std::pair<int, int>> nums;
            for (int i = 0; i < 9; i++) {
                if (i == 0 || i == 4 || i == 8) {
                    nums.emplace_back(v[i], c[i]);
                }
            }
            std::sort(nums.begin(), nums.end());
            is_sad = nums[0].second == nums[1].second;
            if (is_sad) {
                return is_sad;
            }
        }
        {
            std::vector<std::pair<int, int>> nums;
            for (int i = 0; i < 9; i++) {
                if (i == 2 || i == 4 || i == 6) {
                    nums.emplace_back(v[i], c[i]);
                }
            }
            std::sort(nums.begin(), nums.end());
            is_sad = nums[0].second == nums[1].second;
        }
        return is_sad;
    };

    int sad_cnt = 0;
    int total = 0;
    std::vector<int> order(9);
    for (int i = 0; i < 9; i++) {
        order[i] = i;
    }
    do {
        total++;
        if (search_row(order) || search_column(order) || search_diagonal(order)) {
            sad_cnt++;
        }
    } while (std::next_permutation(order.begin(), order.end()));

    double ans = static_cast<double>(total - sad_cnt) / total;
    std::cout << std::setprecision(9) << ans << std::endl;
    return 0;
}