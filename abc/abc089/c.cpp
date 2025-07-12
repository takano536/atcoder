#include <iostream>
#include <string>
#include <vector>

int main() {
    constexpr int CHAR_NUM = 5;
    int n;
    std::cin >> n;

    std::vector<int> counts(CHAR_NUM);
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        switch (s[0]) {
            case 'M': counts[0]++; break;
            case 'A': counts[1]++; break;
            case 'R': counts[2]++; break;
            case 'C': counts[3]++; break;
            case 'H': counts[4]++; break;
            default: break;
        }
    }

    long long ans = 0;
    for (int i = 0; i < CHAR_NUM; i++) {
        for (int j = i + 1; j < CHAR_NUM; j++) {
            for (int k = j + 1; k < CHAR_NUM; k++)
                ans += static_cast<long long>(counts[i]) * counts[j] * counts[k];
        }
    }

    std::cout << ans << std::endl;
    return 0;
}