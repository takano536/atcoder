#include <bitset>
#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector s(n, std::string());
    for (auto &si : s) {
        std::cin >> si;
    }

    int ans = 1e9;
    for (int digit = 0; digit <= 9; digit++) {
        int time = 0;
        auto curr = 0;
        std::bitset<100> is_stopped;
        while (is_stopped.count() < static_cast<std::size_t>(n)) {
            for (int i = 0; i < n; i++) {
                if (is_stopped.test(i)) {
                    continue;
                }
                if (s[i][curr] == '0' + digit) {
                    is_stopped.set(i);
                    break;
                }
            }
            curr = (curr + 1) % 10;
            time++;
        }
        ans = std::min(time, ans);
    }

    std::cout << ans - 1 << std::endl;
    return 0;
}