#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (auto &num : a) {
        std::cin >> num;
    }

    std::sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) {
            ans++;
            i++;
        }
    }

    std::cout << ans << std::endl;
}