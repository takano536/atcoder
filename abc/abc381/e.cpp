#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::string s;
    std::cin >> s;

    std::vector<int> one_num_cumsum(n + 1), two_num_cumsum(n + 1);
    std::vector<int> sep_idxes;

    for (int i = 0; i < n; i++) {
        switch (s[i]) {
            case '1':
                one_num_cumsum[i + 1]++;
                break;
            case '2':
                two_num_cumsum[i + 1]++;
                break;
            case '/':
                sep_idxes.push_back(i + 1);
                break;
            default:
                std::runtime_error("invalid character");
        }
        one_num_cumsum[i + 1] += one_num_cumsum[i];
        two_num_cumsum[i + 1] += two_num_cumsum[i];
    }

    auto solve = [&]() {
        int l, r;
        std::cin >> l >> r;

        int ok = 0, ng = n + 1;
        while (ng - ok > 1) {
            auto mid = (ok + ng) / 2;

            auto offset = one_num_cumsum[l - 1];
            auto one_iter = std::ranges::lower_bound(one_num_cumsum, mid / 2 + offset);
            if (one_iter == one_num_cumsum.end()) {
                ng = mid;
                continue;
            }
            auto curr_idx = std::max<int>(l, std::distance(one_num_cumsum.begin(), one_iter));

            auto sep_iter = std::ranges::lower_bound(sep_idxes, curr_idx);
            if (sep_iter == sep_idxes.end()) {
                ng = mid;
                continue;
            }
            curr_idx = *sep_iter;

            offset = two_num_cumsum[curr_idx];
            auto two_iter = std::ranges::lower_bound(two_num_cumsum, mid / 2 + offset);
            if (two_iter == two_num_cumsum.end()) {
                ng = mid;
                continue;
            }
            curr_idx = std::max<int>(curr_idx, std::distance(two_num_cumsum.begin(), two_iter));

            (curr_idx <= r ? ok : ng) = mid;
        }

        std::cout << ok << std::endl;
    };

    while (q--) solve();
    return 0;
}