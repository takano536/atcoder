#include <iostream>
#include <map>

int main() {
    int n;
    std::cin >> n;

    std::map<int, int> adds, subs;
    for (int i = 1; i <= n; i++) {
        int a;
        std::cin >> a;
        adds[i + a]++, subs[i - a]++;
    }

    long long ans = 0;
    for (const auto &[k, v] : adds) {
        ans += static_cast<long long>(v) * subs[k];
    }

    std::cout << ans << std::endl;
    return 0;
}