#include <iostream>
#include <numeric>
#include <set>
#include <vector>

int main() {
    int n, w;
    std::cin >> n >> w;
    std::vector<int> a(n);
    for (auto &ai : a) {
        std::cin >> ai;
    }

    std::set<int> ans;
    for (int i = 0; i < n; i++) {
        if (a[i] > w) {
            continue;
        }
        ans.insert(a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto total = a[i] + a[j];
            if (total > w) {
                continue;
            }
            ans.insert(total);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                auto total = a[i] + a[j] + a[k];
                if (total > w) {
                    continue;
                }
                ans.insert(total);
            }
        }
    }

    std::cout << ans.size() << std::endl;
    return 0;
}