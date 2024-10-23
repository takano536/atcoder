#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <utility>

int main() {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    constexpr std::array<std::pair<int, int>, 8> COEFFS = {
        std::make_pair(+1, +2),
        std::make_pair(+1, -2),
        std::make_pair(-1, +2),
        std::make_pair(-1, -2),
        std::make_pair(+2, +1),
        std::make_pair(+2, -1),
        std::make_pair(-2, +1),
        std::make_pair(-2, -1),
    };

    auto get_coords = [&COEFFS](const int x, const int y) -> std::set<std::pair<int, int>> {
        std::set<std::pair<int, int>> ret;
        for (const auto &[cx, cy] : COEFFS) ret.insert({x + cx, y + cy});
        return ret;
    };

    std::set<std::pair<int, int>> intersecs;
    std::ranges::set_intersection(
        get_coords(x1, y1),
        get_coords(x2, y2),
        std::inserter(intersecs, intersecs.end())
    );

    std::cout << (intersecs.size() > 0 ? "Yes" : "No") << std::endl;
    return 0;
}