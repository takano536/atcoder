#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> ans(2 * n + 1 + 1);
    ans[1] = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        std::cin >> a;
        ans[i * 2] = ans[a] + 1;
        ans[i * 2 + 1] = ans[a] + 1;
    }

    for (int i = 1; i <= 2 * n + 1; i++) std::cout << ans[i] << std::endl;

    return 0;
}