#include <iostream>
#include <map>
#include <utility>
#include <vector>

#include <atcoder/modint>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> cards(n);
    std::map<int, int> num_cnt;
    for (auto &card : cards) {
        std::cin >> card.first >> card.second;
    }

    std::vector<std::vector<atcoder::modint998244353>> dp(n, std::vector<atcoder::modint998244353>(2));
    dp[0][0] = 1, dp[0][1] = 1;

    for (int i = 1; i < n; i++) {
        dp[i][0] += dp[i - 1][0] * static_cast<int>(cards[i - 1].first != cards[i].first);
        dp[i][1] += dp[i - 1][0] * static_cast<int>(cards[i - 1].first != cards[i].second);
        dp[i][0] += dp[i - 1][1] * static_cast<int>(cards[i - 1].second != cards[i].first);
        dp[i][1] += dp[i - 1][1] * static_cast<int>(cards[i - 1].second != cards[i].second);
    }

    std::cout << (dp[n - 1][1] + dp[n - 1][0]).val() << std::endl;
    return 0;
}