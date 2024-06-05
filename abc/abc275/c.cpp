#include <array>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

int main() {
    constexpr int N = 9;
    std::vector<std::string> s(N);
    for (auto &si : s) std::cin >> si;

    std::vector<std::pair<int, int>> coords;
    for (int i = 0; const auto &si : s) {
        for (int j = 0; const auto &c : si) {
            if (c == '#') coords.push_back({i, j});
            j++;
        }
        i++;
    }

    constexpr std::array<std::pair<int, int>, 4> COEFS = {
        std::make_pair(+1, +1),
        std::make_pair(+1, -1),
        std::make_pair(-1, -1),
        std::make_pair(-1, +1),
    };

    std::set<std::set<std::pair<int, int>>> combs;
    for (const auto &[c1_i, c1_j] : coords) {
        for (const auto &[c2_i, c2_j] : coords) {

            if (c1_i == c2_i && c1_j == c2_j) continue;
            std::pair<int, int> dir = {std::abs(c2_i - c1_i), std::abs(c2_j - c1_j)};
            std::pair<int, int> curr = {c1_i, c1_j};
            std::set<std::pair<int, int>> comb;

            bool is_square = true;
            for (const auto &[ci, cj] : COEFS) {
                comb.insert(curr);

                auto [di, dj] = dir;
                di *= ci, dj *= cj;

                auto [ni, nj] = curr;
                ni += di, nj += dj;

                if (ni < 0 || ni >= N || nj < 0 || nj >= N) {
                    is_square = false;
                    break;
                }
                if (s[ni][nj] != '#') {
                    is_square = false;
                    break;
                }

                curr = {ni, nj};
                dir = {std::abs(dj), std::abs(di)};
            }

            if (is_square) combs.insert(comb);
        }
    }

    std::cout << combs.size() << std::endl;
    return 0;
}