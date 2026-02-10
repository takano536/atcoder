#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    constexpr int A_MAX = 1e6;
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    std::vector<int> digits(A_MAX + 1 + 1);
    for (const auto &ai : a) digits[0]++, digits[ai]--;
    for (int i = 0; i < static_cast<int>(digits.size()); i++) {
        digits[i + 1] += digits[i];
    }

    std::string ans;
    int carry_up = 0;
    for (int i = 0; i < static_cast<int>(digits.size()); i++) {
        const auto digit_str = std::to_string(digits[i] + carry_up);
        ans += digit_str.back();
        carry_up = (digit_str.size() == 1 ? 0 : std::stoi(digit_str.substr(0, digit_str.size() - 1)));
    }
    while (ans.back() == '0') ans.pop_back();
    std::ranges::reverse(ans);

    std::cout << ans << std::endl;
    return 0;
}