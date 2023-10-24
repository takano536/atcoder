#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> w(n), x(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i] >> x[i];
    }

    int ans = 0;
    for (int i = 0; i <= 24; i++) {
        int total = 0;
        for (int j = 0; j < n; j++) {
            int start = (x[j] + i) % 24;
            int end = (x[j] + i + 1) % 24;
            if (9 <= start && start <= 18 && 9 <= end && end <= 18) {
                total += w[j];
            }
        }
        ans = std::max(ans, total);
    }

    std::cout << ans << std::endl;
    return 0;
}