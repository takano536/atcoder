#include <iostream>
#include <utility>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n), idxes(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
        idxes[a[i]] = i;
    }

    std::vector<std::pair<int, int>> ans;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == i) {
            continue;
        }
        ans.push_back(std::make_pair(i + 1, idxes[i] + 1));
        std::swap(a[i], a[idxes[i]]);
        std::swap(idxes[a[i]], idxes[a[idxes[i]]]);
    }

    std::cout << ans.size() << std::endl;
    for (const auto &[l, r] : ans) {
        std::cout << l << " " << r << std::endl;
    }
    return 0;
}