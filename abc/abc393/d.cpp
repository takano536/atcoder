#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<int> one_idxes;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') one_idxes.push_back(i);
    }

    auto center = one_idxes.size() / 2;

    auto calc_swap_count = [&](int center) -> long long {
        long long ans = 0;
        for (int i = 0; i < static_cast<int>(one_idxes.size()); i++) {
            if (i == center) continue;
            if (i < center) {
                ans += one_idxes[center] - one_idxes[i] - (center - i);
            } else {
                ans += one_idxes[i] - one_idxes[center] - (i - center);
            }
        }
        return ans;
    };

    if (one_idxes.size() % 2 == 0) {
        std::cout << std::min(calc_swap_count(center), calc_swap_count(center - 1)) << std::endl;
    } else {
        std::cout << calc_swap_count(center) << std::endl;
    }
    return 0;
}