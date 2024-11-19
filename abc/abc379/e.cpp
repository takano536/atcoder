#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::ranges::reverse(s);
    std::vector<long long> cumsum(n + 1), cumcumsum(n + 1);
    for (int i = 0; i < n; i++) cumsum[i + 1] = cumsum[i] + (s[i] - '0');
    for (int i = 0; i < n; i++) cumcumsum[i + 1] = cumcumsum[i] + cumsum[i + 1];

    std::string ans;
    long long carry = 0;
    for (int i = 0; i < n; i++) {
        carry += cumcumsum[n];
        ans += std::to_string(carry % 10);
        cumcumsum[n] -= static_cast<long long>(s[i] - '0') * (n - i);
        carry /= 10;
    }
    if (carry > 0) ans += std::to_string(carry);

    std::ranges::reverse(ans);
    std::cout << ans << std::endl;
}