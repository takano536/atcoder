#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::string s;
    std::cin >> s;

    std::pair<std::vector<int>, std::vector<int>> cumsums = {
        std::vector<int>(n + 1),
        std::vector<int>(n + 1),
    };
    std::vector<int> sep_idxes;

    for (int i = 0; i < n; i++) {
        switch (s[i]) {
            case '1':
                cumsums.first[i + 1]++;
                break;
            case '2':
                cumsums.second[i + 1]++;
                break;
            case '/':
                sep_idxes.push_back(i + 1);
                break;
            default:
                std::runtime_error("invalid character");
        }
        cumsums.first[i + 1] += cumsums.first[i];
        cumsums.second[i + 1] += cumsums.second[i];
    }

    auto solve = [&]() {
        int l, r;
        std::cin >> l >> r;

        int ok = 0, ng = n + 1;
        while (ng - ok > 1) {
            auto mid = (ok + ng) / 2;

            auto offset = cumsums.first[l - 1];
            auto iter = std::ranges::lower_bound(cumsums.first, mid / 2 + offset);
            if (iter == cumsums.first.end()) {
                ng = mid;
                continue;
            }
            auto idx = std::max<int>(l, std::distance(cumsums.first.begin(), iter));

            iter = std::ranges::lower_bound(sep_idxes, idx);
            if (iter == sep_idxes.end()) {
                ng = mid;
                continue;
            }
            idx = *iter;

            offset = cumsums.second[idx];
            iter = std::ranges::lower_bound(cumsums.second, mid / 2 + offset);
            if (iter == cumsums.second.end()) {
                ng = mid;
                continue;
            }
            idx = std::max<int>(idx, std::distance(cumsums.second.begin(), iter));

            (idx <= r ? ok : ng) = mid;
        }

        std::cout << ok << std::endl;
    };

    while (q--) solve();
    return 0;
}