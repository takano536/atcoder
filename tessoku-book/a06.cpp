#include <iostream>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a_cumsum(n + 1);
    for (int i = 1; i <= n; i++) {
        int a;
        std::cin >> a;
        a_cumsum[i] = a + a_cumsum[i - 1];
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;
        std::cout << a_cumsum[r] - a_cumsum[l - 1] << std::endl;
    }
    return 0;
}