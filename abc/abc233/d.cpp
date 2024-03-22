#include <cassert>
#include <iostream>
#include <map>
#include <vector>

int main() {
    int n;
    long long k;
    std::cin >> n >> k;
    std::vector<long long> a(n);
    for (auto &ai : a) {
        std::cin >> ai;
    }

    std::vector<long long> cumsum(n + 1);
    for (int i = 0; i < n; i++) {
        cumsum[i + 1] = cumsum[i] + a[i];
    }

    std::map<long long, int> cnts;
    long long ans = 0;
    for (const auto &s : cumsum) {
        if (cnts.contains(s)) {
            ans += cnts.at(s);
        }
        cnts[s + k]++;
    }

    std::cout << ans << std::endl;
    return 0;
}