#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n * 3);
    std::vector<std::pair<int, int>> ans(n);
    std::vector<int> cnts(n);
    for (int i = 0; i < n * 3; i++) {
        std::cin >> a[i];
        a[i]--;
        cnts[a[i]]++;
        if (cnts[a[i]] == 2) {
            ans[a[i]] = {i, a[i] + 1};
        }
    }

    std::sort(ans.begin(), ans.end());

    for (int i = 0; i < n; i++) {
        std::cout << ans[i].second << ' ';
    }
    std::cout << std::endl;
    return 0;
}