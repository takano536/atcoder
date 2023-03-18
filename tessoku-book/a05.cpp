#include <iostream>

int main()
{
    int n, k;
    std::cin >> n >> k;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans += static_cast<int>(0 < k - i - j && k - i - j <= n);
        }
    }

    std::cout << ans << std::endl;
}