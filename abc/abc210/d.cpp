#include <iostream>
#include <vector>

const long long INF = 1e18;
std::vector<std::vector<long long>> flip_horizontally(const std::vector<std::vector<long long>> &matrix);
long long calc_cost(const std::vector<std::vector<long long>> &a, long long c);

int main() {
    int h, w, c;
    std::cin >> h >> w >> c;
    std::vector a(h, std::vector<long long>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::cin >> a[i][j];
        }
    }

    std::cout << std::min(calc_cost(a, c), calc_cost(flip_horizontally(a), c)) << std::endl;
    return 0;
}

std::vector<std::vector<long long>> flip_horizontally(const std::vector<std::vector<long long>> &matrix) {
    int h = matrix.size();
    int w = matrix[0].size();
    std::vector res(h, std::vector<long long>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            res[i][j] = matrix[i][w - j - 1];
        }
    }
    return res;
}

long long calc_cost(const std::vector<std::vector<long long>> &a, long long c) {
    const int h = a.size();
    const int w = a[0].size();

    std::vector dp(h + 1, std::vector<long long>(w + 1, INF));

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            dp[i][j] = std::min(dp[i][j], a[i - 1][j - 1]);
            dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + c);
            dp[i][j] = std::min(dp[i][j], dp[i][j - 1] + c);
        }
    }

    long long ans = INF;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            ans = std::min(ans, dp[i - 1][j] + c + a[i - 1][j - 1]);
            ans = std::min(ans, dp[i][j - 1] + c + a[i - 1][j - 1]);
        }
    }

    return ans;
}
