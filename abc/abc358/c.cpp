#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> s(n);
    for (int i = 0; i < n; i++) {
        std::string si;
        std::cin >> si;
        int bit = 0;
        for (int j = 0; j < m; j++) {
            if (si[j] == 'o') {
                bit |= 1 << j;
            }
        }
        s[i] = bit;
    }

    int ans = 1e9;
    for (int bit = 0; bit < (1 << n); bit++) {
        std::vector<int> idxes;
        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) {
                idxes.push_back(i);
            }
        }

        int is_satisfied = 0;
        for (const auto &i : idxes) {
            is_satisfied |= s[i];
        }
        if ((1 << m) - 1 == is_satisfied) {
            ans = std::min<int>(ans, idxes.size());
        }
    }

    std::cout << (ans == 1e9 ? -1 : ans) << std::endl;
    return 0;
}