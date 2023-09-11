#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, a, b;
    std::cin >> n >> a >> b;

    std::string s;
    std::cin >> s;

    s += s;
    long long ans = 1e18;
    for (int i = 0; i < n; i++) {
        auto curr_s = s.substr(i, n);
        long long curr_ans = static_cast<long long>(i) * a;
        for (int j = 0; j < n / 2; j++) {
            if (curr_s[j] != curr_s[n - j - 1]) {
                curr_ans += b;
            }
        }
        ans = std::min(ans, curr_ans);
    }

    std::cout << ans << std::endl;
    return 0;
}