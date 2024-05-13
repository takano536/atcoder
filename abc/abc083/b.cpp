#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    int a, b;
    std::cin >> a >> b;

    auto sum_digits = [](const std::string &s) {
        int ret = 0;
        for (auto c : s) {
            ret += c - '0';
        }
        return ret;
    };

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        auto i_str = std::to_string(i);
        int total = sum_digits(i_str);
        ans += (a <= total && total <= b ? i : 0);
    }

    std::cout << ans << std::endl;
    return 0;
}