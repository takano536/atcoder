#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> c(9);
    for (int i = 0; i < 9; i++) {
        std::cin >> c[i];
    }

    int sad_cnt = 0;
    int total = 0;
    std::vector<int> order(9);
    std::iota(order.begin(), order.end(), 0);

    do {
        total++;

        std::vector<std::vector<std::pair<int, int>>> array_infos;
        // row
        array_infos.push_back({
            std::make_pair(order[0], c[0]),
            std::make_pair(order[1], c[1]),
            std::make_pair(order[2], c[2]),
        });
        array_infos.push_back({
            std::make_pair(order[3], c[3]),
            std::make_pair(order[4], c[4]),
            std::make_pair(order[5], c[5]),
        });
        array_infos.push_back({
            std::make_pair(order[6], c[6]),
            std::make_pair(order[7], c[7]),
            std::make_pair(order[8], c[8]),
        });
        // column
        array_infos.push_back({
            std::make_pair(order[0], c[0]),
            std::make_pair(order[3], c[3]),
            std::make_pair(order[6], c[6]),
        });
        array_infos.push_back({
            std::make_pair(order[1], c[1]),
            std::make_pair(order[4], c[4]),
            std::make_pair(order[7], c[7]),
        });
        array_infos.push_back({
            std::make_pair(order[2], c[2]),
            std::make_pair(order[5], c[5]),
            std::make_pair(order[8], c[8]),
        });
        // diagonal
        array_infos.push_back({
            std::make_pair(order[0], c[0]),
            std::make_pair(order[4], c[4]),
            std::make_pair(order[8], c[8]),
        });
        array_infos.push_back({
            std::make_pair(order[2], c[2]),
            std::make_pair(order[4], c[4]),
            std::make_pair(order[6], c[6]),
        });

        for (auto array_info : array_infos) {
            std::sort(array_info.begin(), array_info.end());
            if (array_info[0].second == array_info[1].second) {
                sad_cnt++;
                break;
            }
        }
    } while (std::next_permutation(order.begin(), order.end()));

    double ans = static_cast<double>(total - sad_cnt) / total;
    std::cout << std::setprecision(9) << ans << std::endl;
    return 0;
}