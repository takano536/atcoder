#include <iostream>
#include <vector>

int main() {
    int n, t;
    std::cin >> n >> t;

    std::vector<int> rows(n);
    std::vector<int> cols(n);
    std::vector<int> diag(2);

    int ans = -1;
    for (int i = 0; i < t; i++) {
        int a;
        std::cin >> a;
        a--;
        rows[a % n]++;
        cols[a / n]++;
        if (a % n == a / n) {
            diag[0]++;
        }
        if (a % n + a / n == n - 1) {
            diag[1]++;
        }
        if (rows[a % n] == n || cols[a / n] == n || diag[0] == n || diag[1] == n) {
            ans = i + 1;
            break;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}