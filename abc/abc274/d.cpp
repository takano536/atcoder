#include <iostream>
#include <map>
#include <utility>
#include <vector>

int main() {
    int n;
    std::pair<int, int> dst;
    std::cin >> n >> dst.first >> dst.second;

    std::vector<int> x, y;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        (i % 2 ? y : x).push_back(a);
    }

    std::vector dp_x(x.size(), std::map<int, bool>());
    dp_x[0][x[0]] = true;
    for (int i = 1; i < static_cast<int>(x.size()); i++) {
        for (const auto &[k, _] : dp_x[i - 1]) {
            dp_x[i][k + x[i]] = true;
            dp_x[i][k - x[i]] = true;
        }
    }

    std::vector dp_y(y.size(), std::map<int, bool>());
    dp_y[0][y[0]] = true, dp_y[0][-y[0]] = true;
    for (int i = 1; i < static_cast<int>(y.size()); i++) {
        for (const auto &[k, _] : dp_y[i - 1]) {
            dp_y[i][k + y[i]] = true;
            dp_y[i][k - y[i]] = true;
        }
    }

    const auto [dst_x, dst_y] = dst;
    std::cout << (dp_x[x.size() - 1].contains(dst_x) && dp_y[y.size() - 1].contains(dst_y) ? "Yes" : "No") << std::endl;
    return 0;
}