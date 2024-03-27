#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main() {
    long long x;
    std::cin >> x;

    std::vector<long long> arith_nums(99);
    std::iota(arith_nums.begin(), arith_nums.end(), 1);
    for (int digit_cnt = 3; digit_cnt <= 18; digit_cnt++) {
        for (int start_num = 1; start_num <= 9; start_num++) {
            for (int diff = -9; diff <= 9; diff++) {

                std::string num;
                int curr_num = start_num;
                num += '0' + curr_num;
                bool is_arith_num = true;
                for (int i = 1; i < digit_cnt; i++) {
                    curr_num += diff;
                    if (curr_num < 0 || curr_num > 9) {
                        is_arith_num = false;
                        break;
                    }
                    num += '0' + curr_num;
                }
                if (is_arith_num) {
                    arith_nums.push_back(std::stoll(num));
                }
            }
        }
    }

    std::cout << *std::ranges::lower_bound(arith_nums, x) << std::endl;
    return 0;
}