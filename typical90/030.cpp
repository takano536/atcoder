#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> prime_cnts(n + 1);
    int ans = 0;
    for (int num = 2; num <= n; num++) {
        if (prime_cnts[num] > 0) {
            continue;
        }
        for (int multiple = num; multiple <= n; multiple += num) {
            prime_cnts[multiple]++;
            if (prime_cnts[multiple] == k) {
                ans++;
            }
        }
    }

    std::cout << ans << std::endl;
    return 0;
}