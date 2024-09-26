#include <iostream>

#include <atcoder/modint>

int main() {
    long long n;
    int k;
    std::cin >> n >> k;

    atcoder::modint1000000007 ans = k;
    if (n >= 2) ans *= (k - 1);
    if (n >= 3) ans *= atcoder::modint1000000007(k - 2).pow(n - 2);

    std::cout << ans.val() << std::endl;
    return 0;
}