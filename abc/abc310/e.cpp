#include <array>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> s(n);
    for (auto &si : s) {
        char c;
        std::cin >> c;
        si = c - '0';
    }

    std::vector<std::array<int, 2>> cnts(n);
    if (s[0] == 0) cnts[0][0] = 1;
    if (s[0] == 1) cnts[0][1] = 1;
    long long ans = cnts[0][1];
    for (int i = 1; i < n; i++) {
        if (s[i] == 0) {
            cnts[i][1] += cnts[i - 1][0] + cnts[i - 1][1];
            cnts[i][0]++;
        }
        if (s[i] == 1) {
            cnts[i][0] += cnts[i - 1][1];
            cnts[i][1] += cnts[i - 1][0];
            cnts[i][1]++;
        }
        ans += cnts[i][1];
    }

    std::cout << ans << std::endl;
    return 0;
}