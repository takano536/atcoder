#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    int cnt = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == i + 1) {
            cnt++;
        } else if (a[a[i] - 1] == i + 1) {
            ans++;
        }
    }
    ans /= 2;

    ans += static_cast<long long>(cnt - 1) * cnt / 2;
    std::cout << ans << std::endl;
    return 0;
}