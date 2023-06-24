#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

const int MAX_H = 10;
const int MAX_W = 10;

std::set<std::pair<int, int>> sheet2coords(std::vector<std::string> &sheet) {
    std::set<std::pair<int, int>> coords;
    int h = sheet.size();
    int w = sheet[0].size();
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (sheet[i][j] == '#') {
                coords.insert({i, j});
            }
        }
    }
    return coords;
}

std::set<std::pair<int, int>> normalize(std::set<std::pair<int, int>> &coords) {
    std::set<std::pair<int, int>> normalized_coords;
    int min_h = MAX_H;
    int min_w = MAX_W;
    for (const auto &coord : coords) {
        min_h = std::min(min_h, coord.first);
        min_w = std::min(min_w, coord.second);
    }
    for (const auto &coord : coords) {
        normalized_coords.insert({coord.first - min_h, coord.second - min_w});
    }
    return normalized_coords;
}

int main() {
    int ha, wa;
    std::cin >> ha >> wa;
    std::vector<std::string> a(ha);
    for (auto &s : a) {
        std::cin >> s;
    }

    int hb, wb;
    std::cin >> hb >> wb;
    std::vector<std::string> b(hb);
    for (auto &s : b) {
        std::cin >> s;
    }

    int hx, wx;
    std::cin >> hx >> wx;
    std::vector<std::string> x(hx);
    for (auto &s : x) {
        std::cin >> s;
    }

    auto a_coords = sheet2coords(a);
    auto b_coords = sheet2coords(b);
    auto x_coords = sheet2coords(x);

    a_coords = normalize(a_coords);
    b_coords = normalize(b_coords);
    x_coords = normalize(x_coords);

    bool satisfies = false;
    for (int ia = 0; ia < MAX_H; ia++) {
        for (int ja = 0; ja < MAX_W; ja++) {
            for (int ib = 0; ib < MAX_H; ib++) {
                for (int jb = 0; jb < MAX_W; jb++) {
                    std::set<std::pair<int, int>> black_coords;
                    for (const auto &coord : a_coords) {
                        black_coords.insert({coord.first + ia, coord.second + ja});
                    }
                    for (const auto &coord : b_coords) {
                        black_coords.insert({coord.first + ib, coord.second + jb});
                    }
                    if (x_coords == normalize(black_coords)) {
                        satisfies = true;
                    }
                }
            }
        }
    }

    std::cout << (satisfies ? "Yes" : "No") << std::endl;
    return 0;
}