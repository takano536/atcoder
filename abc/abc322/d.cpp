#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

int main() {
    const int N = 3;
    const int SIZE = 4;

    std::vector<std::vector<std::string>> p(N, std::vector<std::string>(SIZE));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cin >> p[i][j];
        }
    }

    auto rotate = [&N, &SIZE](std::vector<std::string> &mino) -> void {
        std::vector<std::string> rotated = mino;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                rotated[i][j] = mino[SIZE - j - 1][i];
            }
        }
        mino = rotated;
    };

    auto is_movable = [&N, &SIZE](std::vector<std::string> &mino, const std::pair<int, int> &dist) -> bool {
        std::vector<std::string> moved(SIZE, std::string(SIZE, '.'));
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (mino[i][j] != '#') {
                    continue;
                }
                int new_i = i + dist.first;
                int new_j = j + dist.second;
                if (new_i < 0 || new_i >= SIZE || new_j < 0 || new_j >= SIZE) {
                    return false;
                }
                moved[new_i][new_j] = '#';
            }
        }
        mino = moved;
        return true;
    };

    auto fits = [&N, &SIZE](const std::vector<std::vector<std::string>> &minos) -> bool {
        std::vector<std::string> field(SIZE, std::string(SIZE, '.'));
        for (const auto &mino : minos) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    if (mino[i][j] != '#') {
                        continue;
                    }
                    if (field[i][j] == '#') {
                        return false;
                    }
                    field[i][j] = '#';
                }
            }
        }
        for (const auto &s : field) {
            for (const auto &c : s) {
                if (c == '.') {
                    return false;
                }
            }
        }
        return true;
    };

    auto recursive_search = [&](auto recursive_search, std::vector<std::vector<std::string>> &minos, int depth) -> void {
        if (depth == N) {
            if (fits(minos)) {
                std::cout << "Yes" << std::endl;
                exit(0);
            }
            return;
        }
        for (int i = -(SIZE - 1); i <= (SIZE - 1); i++) {
            for (int j = -(SIZE - 1); j <= (SIZE - 1); j++) {
                std::vector<std::vector<std::string>> minos_copy = minos;
                if (is_movable(minos_copy[depth], {i, j})) {
                    recursive_search(recursive_search, minos_copy, depth + 1);
                }
            }
        }
        return;
    };

    for (int s = 0; s < 4; s++) {
        for (int t = 0; t < 4; t++) {
            recursive_search(recursive_search, p, 0);
            rotate(p[0]);
        }
        rotate(p[1]);
    }

    std::cout << "No" << std::endl;
    return 0;
}