#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#include <atcoder/modint>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> seqs(n);
    int max_a = 0;
    for (auto &seq : seqs) {
        std::cin >> seq.first;
        max_a = std::max(max_a, seq.first);
    }
    for (auto &seq : seqs) {
        std::cin >> seq.second;
    }

    std::ranges::sort(seqs);
    std::vector dp(n, std::vector<atcoder::modint>(max_a + 1));
    dp[0][0] = 1;
    dp[0][seqs[0].second] = 1;

    atcoder::modint ans = static_cast<int>(seqs[0].first >= seqs[0].second);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= max_a; j++) {
            dp[i][j] += dp[i - 1][j];
            if (j - seqs[i].second < 0 || dp[i - 1][j - seqs[i].second].val() == 0) {
                continue;
            }

            dp[i][j] += dp[i - 1][j - seqs[i].second];
            if (j > 0 && seqs[i].first >= j) {
                ans += dp[i - 1][j - seqs[i].second];
            }
        }
    }

    std::cout << ans.val() << std::endl;
    return 0;
}