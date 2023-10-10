#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<bool> dp(k + 1);  // 太郎の番かつ残りの石がi個のとき、太郎が勝つかどうか
    dp[0] = false;

    for (int i = 1; i <= k; i++) {
        bool is_win = false;
        for (int j = 0; j < n; j++) {
            if (i - a[j] < 0) {
                continue;
            }
            is_win = is_win || !dp[i - a[j]];
        }
        dp[i] = is_win;
    }

    std::cout << (dp[k] ? "First" : "Second") << std::endl;
    return 0;
}