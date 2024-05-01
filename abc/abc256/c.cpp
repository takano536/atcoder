#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

int main() {
    std::array<int, 3> h, w;
    for (auto &hi : h) {
        std::cin >> hi;
    }
    for (auto &wi : w) {
        std::cin >> wi;
    }

    auto is_satisfied = [&h, &w](std::array<int, 9> cells) -> bool {
        if (!std::ranges::all_of(cells, [](int x) { return x > 0; })) {
            return false;
        }
        for (int i = 0; const auto hi : h) {
            if (cells[i] + cells[i + 3] + cells[i + 6] != hi) {
                return false;
            }
            i++;
        }
        for (int i = 0; const auto wi : w) {
            if (cells[i * 3] + cells[i * 3 + 1] + cells[i * 3 + 2] != wi) {
                return false;
            }
            i++;
        }
        return true;
    };

    int ans = 0;
    for (int c0 = 1; c0 <= 28; c0++) {
        std::array<int, 9> cells;
        for (int c1 = 1; c1 <= 28; c1++) {
            cells[0] = c0, cells[1] = c1;
            cells[2] = w[0] - cells[0] - cells[1];

            for (int c3 = 1; c3 <= 28; c3++) {
                for (int c4 = 1; c4 <= 28; c4++) {
                    cells[3] = c3, cells[4] = c4;
                    cells[5] = w[1] - cells[3] - cells[4];

                    cells[6] = h[0] - cells[0] - cells[3];
                    cells[7] = h[1] - cells[1] - cells[4];
                    cells[8] = h[2] - cells[2] - cells[5];

                    ans += static_cast<int>(is_satisfied(cells));
                }
            }
        }
    }

    std::cout << ans << std::endl;
    return 0;
}