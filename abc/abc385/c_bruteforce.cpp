#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> h(n);
    for (auto &hi : h) std::cin >> hi;

    int ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            int num = 1;
            for (int k = i + j; k < n; k += j) {
                if (h[k] != h[k - j]) break;
                num++;
            }
            ans = std::max(num, ans);
        }
    }

    std::cout << ans << std::endl;
    return 0;
}