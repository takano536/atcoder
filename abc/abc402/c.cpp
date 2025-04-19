#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector dishes(n, std::vector<int>());
    std::vector<int> cnts(m);
    for (int i = 0; i < m; i++) {
        int k;
        std::cin >> k;
        cnts[i] = k;
        for (int j = 0; j < k; j++) {
            int x;
            std::cin >> x;
            dishes[x - 1].push_back(i);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int b;
        std::cin >> b;
        b--;

        for (const auto &j : dishes[b]) {
            cnts[j]--;
            if (cnts[j] == 0) ans++;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}