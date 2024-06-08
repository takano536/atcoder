#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <atcoder/modint>

int main() {
    long long n;
    std::cin >> n;

    std::string n_str = std::to_string(n);
    std::ranges::reverse(n_str);

    atcoder::modint ans;
    atcoder::modint r = atcoder::modint(10).pow(n_str.size());
    for (int i = 0; const auto &c : n_str) {
        atcoder::modint a = atcoder::modint(10).pow(i) * (c - '0');
        ans += a * (r.pow(n) - 1) / (r - 1);
        i++;
    }

    std::cout << ans.val() << std::endl;
}