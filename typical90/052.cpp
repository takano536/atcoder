#include <iostream>

#include <atcoder/modint>

int main() {
    constexpr int NUM = 6;

    int n;
    std::cin >> n;

    atcoder::modint1000000007 ans = 1;
    for (int i = 0; i < n; i++) {
        int total = 0;
        for (int j = 0; j < NUM; j++) {
            int a;
            std::cin >> a;
            total += a;
        }
        ans *= total;
    }

    std::cout << ans.val() << std::endl;
    return 0;
}