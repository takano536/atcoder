#include <iostream>
#include <map>

int main() {
    const int MAX_A = 1e6;

    int a, n;
    std::cin >> a >> n;

    std::map<int, int> dp;
    dp[1] = 0;
    bool should_continue = true;
    while (should_continue) {
        bool is_found = false;
        for (const auto &[key, value] : dp) {
            std::string str = std::to_string(key);
            str = str.back() + str.substr(0, str.size() - 1);
            long long next = std::stoi(str);
            if (next <= MAX_A && str[0] != '0' && (!dp.contains(next) || dp[next] > value + 1)) {
                is_found = true;
                dp[next] = value + 1;
            }
            next = static_cast<long long>(key) * a;
            if (next <= MAX_A && (!dp.contains(next) || dp[next] > value + 1)) {
                is_found = true;
                dp[next] = value + 1;
            }
        }
        if (!is_found) {
            should_continue = false;
        }
    }
    std::cout << (dp.contains(n) ? dp[n] : -1) << std::endl;
    return 0;
}