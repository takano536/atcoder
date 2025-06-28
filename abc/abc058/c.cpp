#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    constexpr int INF = 1e9;

    int n;
    std::cin >> n;
    std::vector<std::string> s(n);
    for (auto &si : s) std::cin >> si;

    std::string ans;
    for (char c = 'a'; c <= 'z'; c++) {
        int available_count = INF;
        for (const auto &si : s) {
            const int c_count = std::ranges::count(si, c);
            available_count = std::min(c_count, available_count);
        }
        ans += std::string(available_count, c);
    }

    std::cout << ans << std::endl;
    return 0;
}