#include <iostream>
#include <vector>

int main() {
    int d, n;
    std::cin >> d >> n;

    std::vector<int> cnts(d);
    for (int i = 0; i < n; i++) {
        int l, r;
        std::cin >> l >> r;
        cnts[l - 1]++;
        cnts[r]--;
    }

    int curr_cnt = 0;
    for (const auto &cnt : cnts) {
        curr_cnt += cnt;
        std::cout << curr_cnt << std::endl;
    }
    return 0;
}