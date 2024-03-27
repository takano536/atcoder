#include <algorithm>
#include <iostream>
#include <string>

int main() {
    long long k;
    std::cin >> k;

    std::string ans;
    while (k > 0) {
        ans += k % 2 ? '2' : '0';
        k /= 2;
    }
    std::ranges::reverse(ans);
    std::cout << ans << std::endl;
    return 0;
}