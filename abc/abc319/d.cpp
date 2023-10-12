#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> l(n);
    for (int i = 0; i < n; i++) {
        std::cin >> l[i];
    }

    long long ng = *std::max_element(l.begin(), l.end()) - 1;
    long long ok = 1e18;
    while (ok - ng > 1) {
        long long mid = (ok + ng) / 2;
        long long line = 1;
        long long width = 0;
        for (int i = 0; i < n - 1; i++) {
            width += l[i];
            width++;
            if (width + l[i + 1] > mid) {
                line++;
                width = 0;
            }
        }
        if (line <= m) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    std::cout << ok << std::endl;
    return 0;
}