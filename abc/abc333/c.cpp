#include <iostream>
#include <set>
#include <string>

int main() {
    const int MAX_DIGITS = 3;

    int n = 0;
    std::cin >> n;

    std::multiset<std::string> digits;
    for (int i = 0; i < MAX_DIGITS; ++i) {
        digits.insert("1");
    }

    for (int i = 2; i <= n; i++) {
        if (*digits.begin() == *std::next(digits.begin()) && *digits.begin() != "1") {
            int rm_cnt = 0;
            std::string max_digit;
            for (auto iter = digits.begin(); std::next(iter) != digits.end(); iter++) {
                if (*iter == *(std::next(iter))) {
                    if (rm_cnt == 0) {
                        rm_cnt++;
                    }
                    rm_cnt++;
                    max_digit = std::max(*iter, max_digit);
                } else {
                    break;
                }
            }
            for (int j = 0; j < rm_cnt; ++j) {
                digits.erase(digits.begin());
            }
            for (int j = 0; j < rm_cnt - 1; ++j) {
                digits.insert("1");
            }
            digits.insert(max_digit + "1");
            continue;
        }
        auto digit = *digits.begin();
        digits.erase(digits.begin());
        digits.insert(digit + "1");
    }

    long long ans = 0;
    for (auto iter = digits.begin(); iter != digits.end(); iter++) {
        ans += std::stoll(*iter);
    }

    std::cout << ans << std::endl;
    return 0;
}