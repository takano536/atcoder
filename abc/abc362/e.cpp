#include <iostream>
#include <vector>

#include <atcoder/modint>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    // dp[i][j][k]=末項がa_i(1-indexed)、後ろから2番目の数がa_j(1-indexed)、数列の長さがkの数、0=NA
    std::vector dp(n + 1, std::vector(n + 1, std::vector<atcoder::modint>(n + 1)));
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (dp[i][j][k] == 0) continue;
                auto curr = dp[i][j][k];
                for (int next = i + 1; next <= n; next++) {  // 1-indexed
                    if (j != 0 && a[i - 1] - a[j - 1] != a[next - 1] - a[i - 1]) continue;
                    dp[next][i][k + 1] += curr;
                }
            }
        }
    }

    atcoder::modint ans;
    for (int k = 1; k <= n; k++) {
        ans = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                ans += dp[i][j][k];
            }
        }
        std::cout << ans.val() << ' ';
    }
    std::cout << std::endl;
    return 0;
}