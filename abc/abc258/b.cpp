#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> a(n);
    for (auto &ai : a) std::cin >> ai;

    const std::vector<std::pair<int, int>> DIRS = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1},
        {1, 1},
        {-1, -1},
        {1, -1},
        {-1, 1}
    };

    auto create_num = [&](const int i, const int j) {
        auto res = 0LL;

        for (const auto &[di, dj] : DIRS) {
            auto ni = i;
            auto nj = j;
            std::string num = "";
            for (int i = 0; i < n; i++) {
                num += a[ni][nj];
                ni += di, nj += dj;

                if (ni > n - 1) ni = 0;
                if (nj > n - 1) nj = 0;
                if (ni < 0) ni = n - 1;
                if (nj < 0) nj = n - 1;
            }
            res = std::max(std::stoll(num), res);
        }

        return res;
    };

    auto ans = 0LL;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = std::max(create_num(i, j), ans);
        }
    }

    std::cout << ans << std::endl;
    return 0;
}