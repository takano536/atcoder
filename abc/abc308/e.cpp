#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::string a(n, '0');
    for (auto &input : a) {
        std::cin >> input;
    }

    std::string s;
    std::cin >> s;

    std::string sa(2 * n, '0');
    for (int i = 0, j = 0; i < 2 * n && j < n; i += 2, j++) {
        sa[i] = s[j], sa[i + 1] = a[j];
    }

    auto mex = [](int ai, int aj, int ak) {
        int res = -1e9;
        for (int i = 0; i <= 3; i++) {
            if (i == ai || i == aj || i == ak) {
                continue;
            }
            res = i;
            break;
        }
        return res;
    };

    long long ans = 0;
    for (int ai = 0; ai < 3; ai++) {
        for (int aj = 0; aj < 3; aj++) {
            for (int ak = 0; ak < 3; ak++) {

                std::vector<std::string> targets = {"M" + std::to_string(ai), "E" + std::to_string(aj), "X" + std::to_string(ak)};
                std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(3));

                for (int dp_idx = 1, sa_idx = 0; dp_idx <= n && sa_idx < 2 * n; dp_idx++, sa_idx += 2) {

                    std::string chars = sa.substr(sa_idx, 2);

                    for (int i = 0; i < 3; i++) {
                        dp[dp_idx][i] = dp[dp_idx - 1][i];
                    }

                    if (std::find(targets.begin(), targets.end(), chars) == targets.end()) {
                        continue;
                    }

                    switch (chars[0]) {
                        case 'M': {
                            dp[dp_idx][0] += 1;
                            break;
                        }
                        case 'E': {
                            dp[dp_idx][1] += dp[dp_idx - 1][0];
                            break;
                        }
                        case 'X': {
                            dp[dp_idx][2] += dp[dp_idx - 1][1];
                            break;
                        }
                    }
                }

                ans += dp[n][2] * mex(ai, aj, ak);
            }
        }
    }

    std::cout << ans << std::endl;
    return 0;
}