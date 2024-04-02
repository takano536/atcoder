#include <bitset>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    const int MAX_LEN = 60;
    const int NA = -1;

    int a, b;
    std::cin >> a >> b;
    long long c;
    std::cin >> c;

    // dp[下位からi桁目まで見て][X.popcount=j][Y.popcount=k]=(X,Y)
    std::vector dp(MAX_LEN, std::vector(std::max(1, a) + 1, std::vector<std::pair<long long, long long>>(std::max(1, b) + 1, {NA, NA})));
    if (c & (1 << 0)) {
        dp[0][1][0] = {1 << 0, 0};
        dp[0][0][1] = {0, 1 << 0};
    } else {
        dp[0][0][0] = {0, 0};
        dp[0][1][1] = {1 << 0, 1 << 0};
    }

    for (int i = 1; i < MAX_LEN; i++) {
        for (int j = 0; j <= a; j++) {
            for (int k = 0; k <= b; k++) {
                if (dp[i - 1][j][k].first == NA || dp[i - 1][j][k].second == NA) {
                    continue;
                }
                if (c & (1LL << i)) {
                    // cのiビット目が立っている=XかYのどちらかのみを立てる
                    if (j + 1 <= a) {
                        dp[i][j + 1][k] = {dp[i - 1][j][k].first | (1LL << i), dp[i - 1][j][k].second};
                        // std::cout << "dp[" << i << "][" << j + 1 << "][" << k << "]=(" << std::bitset<8>(dp[i][j + 1][k].first) << ',' << std::bitset<8>(dp[i][j + 1][k].second) << ")\n";
                    }
                    if (k + 1 <= b) {
                        dp[i][j][k + 1] = {dp[i - 1][j][k].first, dp[i - 1][j][k].second | (1LL << i)};
                        // std::cout << "dp[" << i << "][" << j << "][" << k + 1 << "]=(" << std::bitset<8>(dp[i][j][k + 1].first) << ',' << std::bitset<8>(dp[i][j][k + 1].second) << ")\n";
                    }
                } else {
                    // cのiビット目が立っていない=XとYの両方を立てるかどちらとも折る
                    if (j + 1 <= a && k + 1 <= b) {
                        dp[i][j + 1][k + 1] = {dp[i - 1][j][k].first | (1LL << i), dp[i - 1][j][k].second | (1LL << i)};
                        // std::cout << "dp[" << i << "][" << j + 1 << "][" << k + 1 << "]=(" << std::bitset<8>(dp[i][j + 1][k + 1].first) << ',' << std::bitset<8>(dp[i][j + 1][k + 1].second) << ")\n";
                    }
                    dp[i][j][k] = dp[i - 1][j][k];
                    // std::cout << "dp[" << i << "][" << j << "][" << k << "]=(" << std::bitset<8>(dp[i][j][k].first) << ',' << std::bitset<8>(dp[i][j][k].second) << ")\n";
                }
            }
        }
    }

    if (dp[MAX_LEN - 1][a][b].first == NA || dp[MAX_LEN - 1][a][b].second == NA) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << dp[MAX_LEN - 1][a][b].first << ' ' << dp[MAX_LEN - 1][a][b].second << std::endl;
    }
    return 0;
}