#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> cumsum(n + 1);
    for (int i = 0; i < m; i++) {
        int l, r;
        std::cin >> l >> r;
        l--, r--;
        cumsum[l]++, cumsum[r + 1]--;
    }

    for (int i = 0; i < n; i++) cumsum[i + 1] += cumsum[i];
    cumsum.pop_back();

    std::cout << *std::ranges::min_element(cumsum) << std::endl;
    return 0;
}