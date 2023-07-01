#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> c(n), d(m);
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> d[i];
    }

    std::vector<int> p(m + 1);
    for (int i = 0; i < m + 1; i++) {
        std::cin >> p[i];
    }

    std::map<std::string, int> prices;
    for (int i = 0; i < m; i++) {
        prices[d[i]] = p[i + 1];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (prices.find(c[i]) == prices.end()) {
            ans += p[0];
        } else {
            ans += prices[c[i]];
        }
    }

    std::cout << ans << std::endl;
    return 0;
}