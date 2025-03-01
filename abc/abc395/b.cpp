#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    n++;

    std::vector ans(n, std::string(n, ' '));

    for (int i = 1; i <= n; i++) {
        const int j = n + 1 - i;
        if (i > j) continue;

        const char curr = i % 2 == 0 ? '.' : '#';
        for (int ii = i; ii < j; ii++) {
            for (int jj = i; jj < j; jj++) ans[ii - 1][jj - 1] = curr;
        }
    }

    for (const auto &s : ans) std::cout << s << std::endl;
    return 0;
}