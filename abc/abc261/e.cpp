#include <array>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    const int MAX_BIT_SIZE = 30;

    int n, c;
    std::cin >> n >> c;

    std::vector<std::pair<int, int>> ops(n);
    for (auto &[t, a] : ops) std::cin >> t >> a;

    std::vector funcs(n + 1, std::vector(MAX_BIT_SIZE, std::array<bool, 2>()));
    for (int i = 0; i < MAX_BIT_SIZE; i++) {
        funcs[0][i][0] = 0;
        funcs[0][i][1] = 1;
    }

    for (int i = 1; i <= n; i++) {
        const auto [t, a] = ops[i - 1];
        for (int j = 0; j < MAX_BIT_SIZE; j++) {
            switch (t) {
                case 1:
                    funcs[i][j][0] = funcs[i - 1][j][0] & ((a & (1 << j)) ? 1 : 0);
                    funcs[i][j][1] = funcs[i - 1][j][1] & ((a & (1 << j)) ? 1 : 0);
                    break;
                case 2:
                    funcs[i][j][0] = funcs[i - 1][j][0] | ((a & (1 << j)) ? 1 : 0);
                    funcs[i][j][1] = funcs[i - 1][j][1] | ((a & (1 << j)) ? 1 : 0);
                    break;
                case 3:
                    funcs[i][j][0] = funcs[i - 1][j][0] ^ ((a & (1 << j)) ? 1 : 0);
                    funcs[i][j][1] = funcs[i - 1][j][1] ^ ((a & (1 << j)) ? 1 : 0);
                    break;
                default:
                    exit(1);
            }
        }
    }

    int ans = c;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < MAX_BIT_SIZE; j++) {
            funcs[i][j][ans & (1 << j) ? 1 : 0] ? ans |= (1 << j) : ans &= ~(1 << j);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}