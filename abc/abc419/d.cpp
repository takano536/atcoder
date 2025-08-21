#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::string s, t;
    std::cin >> s >> t;

    std::vector<int> cumsum(n + 1);
    for (int i = 0; i < m; i++) {
        int l, r;
        std::cin >> l >> r;
        cumsum[l - 1]++, cumsum[r]--;
    }

    for (int i = 0; i < n; i++) cumsum[i + 1] += cumsum[i];

    for (int i = 0; i < n; i++) std::cout << (cumsum[i] % 2 ? t[i] : s[i]);
    std::cout << std::endl;
    return 0;
}