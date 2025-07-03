#include <array>
#include <iostream>
#include <ranges>
#include <tuple>
#include <utility>

int main() {
    constexpr int N = 20;

    constexpr char NA = '?';
    constexpr std::array DIRS = {
        std::make_tuple(+1, 0, 'U'),
        std::make_tuple(0, +1, 'R'),
        std::make_tuple(-1, 0, 'D'),
        std::make_tuple(0, -1, 'L'),
    };

    int _;
    std::cin >> _;

    std::array<std::array<std::pair<int, int>, N>, N> boxes;
    for (auto &row : boxes) {
        for (auto &[w, _] : row) std::cin >> w;
    }
    for (auto &row : boxes) {
        for (auto &[_, d] : row) std::cin >> d;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 && j == 0) continue;
            for (int k = 0; k < i; k++) std::cout << 'D' << "\n";
            for (int k = 0; k < j; k++) std::cout << 'R' << "\n";
            std::cout << '1' << "\n";
            for (int k = 0; k < j; k++) std::cout << 'L' << "\n";
            for (int k = 0; k < i; k++) std::cout << 'U' << "\n";
        }
    }

    return 0;
}