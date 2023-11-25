#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> s(n);
    std::vector<int> vertical_o_cnts(n);
    std::vector<int> holizontal_o_cnts(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
        for (int j = 0; j < n; j++) {
            if (s[i][j] == 'o') {
                vertical_o_cnts[j]++;
                holizontal_o_cnts[i]++;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] != 'o') {
                continue;
            }
            ans += (vertical_o_cnts[j] - 1) * (holizontal_o_cnts[i] - 1);
        }
    }

    std::cout << ans << std::endl;
    return 0;
}