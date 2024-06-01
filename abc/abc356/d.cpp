#include <iostream>

#include <atcoder/modint>

int main() {
    const int MAX_BIT = 60;
    long long n, m;
    std::cin >> n >> m;

    atcoder::modint ans;
    for (int bit = 0; bit < MAX_BIT; bit++) {
        if (!(m & (1LL << bit))) continue;

        long long curr_pow = 1LL << bit;

        ans += (n + 1) / (curr_pow * 2) * curr_pow;
        if ((n - 1) % (curr_pow * 2) != 0) {
            auto rem = (n + 1) % (curr_pow * 2);
            ans += std::max(0LL, rem - curr_pow);
        }
    }

    std::cout << ans.val() << std::endl;
    return 0;
}