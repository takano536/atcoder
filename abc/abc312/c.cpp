#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(m);
    for (auto &ai : a) {
        std::cin >> ai;
    }
    for (auto &bi : b) {
        std::cin >> bi;
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    long long l = -1, r = 1e9 + 1;
    long long mid;
    while (r - l > 1) {
        mid = (l + r) / 2;
        auto a_iter = std::upper_bound(a.begin(), a.end(), mid);
        auto b_iter = std::lower_bound(b.begin(), b.end(), mid);
        int a_cnt = a_iter - a.begin();
        int b_cnt = b.end() - b_iter;

        if (a_cnt < b_cnt) {
            l = mid;
        } else {
            r = mid;
        }
    }

    std::cout << r << std::endl;
    return 0;
}