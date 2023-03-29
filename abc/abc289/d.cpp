#include <iostream>
#include <map>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (auto &num : a) {
        std::cin >> num;
    }

    int m;
    std::cin >> m;

    std::map<int, bool> b;
    for (int i = 0; i < m; i++) {
        int num;
        std::cin >> num;
        b[num] = true;
    }

    int x;
    std::cin >> x;

    std::vector<bool> dp(x + 1);
    dp[0] = true;

    for (int i = 0; i <= x; i++) {
        for (const auto &num : a) {
            if (i + num > x) {
                continue;
            }
            if (dp[i + num]) {
                continue;
            }

            dp[i + num] = dp[i];

            if (b[i + num]) {
                dp[i + num] = false;
            }
        }
    }

    std::cout << (dp[x] ? "Yes" : "No") << std::endl;
}