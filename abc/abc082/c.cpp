#include <iostream>
#include <map>

int main() {
    int n;
    std::cin >> n;

    std::map<int, int> counts;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        counts[a]++;
    }

    int ans = 0;
    for (const auto &[k, v] : counts) ans += (k > v ? v : v - k);

    std::cout << ans << std::endl;
    return 0;
}