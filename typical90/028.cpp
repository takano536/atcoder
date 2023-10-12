#include <iostream>
#include <vector>

int main() {
    const int MAX_SIZE = 1000;

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> field(MAX_SIZE + 1, std::vector<int>(MAX_SIZE + 1));
    for (int q = 0; q < n; q++) {
        int lx, ly, rx, ry;
        std::cin >> lx >> ly >> rx >> ry;

        for (int i = lx; i < rx; i++) {
            field[ly][i]++;
            field[ry][i]--;
        }
    }

    for (int i = 1; i <= MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            field[i][j] += field[i - 1][j];
        }
    }

    std::vector<int> ans(n + 1);
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            ans[field[i][j]]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        std::cout << ans[i] << std::endl;
    }
    return 0;
}