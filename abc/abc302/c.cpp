#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    for (auto &str : s) {
        std::cin >> str;
    }

    std::sort(s.begin(), s.end());
    do {
        bool satisfies = true;
        for (int i = 0; i < n - 1; i++) {
            auto s1 = s[i];
            auto s2 = s[i + 1];
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if (s1[j] != s2[j]) {
                    cnt++;
                }
            }
            if (cnt != 1) {
                satisfies = false;
            }
        }
        if (satisfies) {
            std::cout << "Yes" << std::endl;
            return 0;
        }
    } while (next_permutation(s.begin(), s.end()));

    std::cout << "No" << std::endl;
}