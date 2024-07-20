#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    std::ranges::sort(s);

    int ans = 0;
    do {
        bool is_satisfied = true;
        for (int i = 0; i < n - k + 1; i++) {
            auto substr = s.substr(i, k);
            auto reversed_substr = substr;
            std::ranges::reverse(reversed_substr);
            if (substr == reversed_substr) {
                is_satisfied = false;
                break;
            }
        }
        if (is_satisfied) ans++;

    } while (std::next_permutation(s.begin(), s.end()));

    std::cout << ans << std::endl;
    return 0;
}