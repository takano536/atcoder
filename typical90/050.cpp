#include <iostream>
#include <vector>

#include <atcoder/modint>

int main() {
    int n, l;
    std::cin >> n >> l;

    std::vector<atcoder::modint1000000007> dp(n + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        if (i + l <= n) dp[i + l] += dp[i];
        dp[i + 1] += dp[i];
    }

    std::cout << dp[n].val() << std::endl;
    return 0;
}