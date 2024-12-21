#include <iostream>
#include <map>
#include <ranges>
#include <set>
#include <stdexcept>
#include <utility>
#include <vector>

int main() {
    constexpr long long INF = 8e18;
    constexpr int COORD_MAX = 1e9;
    constexpr int COORD_MIN = -COORD_MAX;

    auto get_dirs = [](const char dir) -> std::pair<int, int> {
        switch (dir) {
            case 'U': return {0, 1};
            case 'D': return {0, -1};
            case 'L': return {-1, 0};
            case 'R': return {1, 0};
            default: throw std::invalid_argument("Invalid direction");
        }
    };

    int n, m;
    long long x, y;
    std::cin >> n >> m >> x >> y;

    std::map<int, std::set<long long>> x_coords, y_coords;
    while (n--) {
        int xi, yi;
        std::cin >> xi >> yi;
        x_coords[yi].insert(xi);
        y_coords[xi].insert(yi);
    }
    for (auto &coords : std::views::values(x_coords)) {
        coords.insert(-INF), coords.insert(INF);
    }
    for (auto &coords : std::views::values(y_coords)) {
        coords.insert(-INF), coords.insert(INF);
    }

    int ans = 0;
    while (m--) {
        char d;
        int c;
        std::cin >> d >> c;

        const auto &[dx, dy] = get_dirs(d);
        const auto nx = x + dx * c, ny = y + dy * c;

        std::vector<std::pair<int, int>> erase_coords;
        switch (d) {
            case 'U': {
                if (!y_coords.contains(x)) break;
                auto &coords = y_coords[x];
                for (auto iter = coords.lower_bound(y); *iter <= ny && iter != coords.end(); iter++) {
                    if (*iter < COORD_MIN || *iter > COORD_MAX) continue;
                    erase_coords.emplace_back(x, *iter);
                }
                break;
            }

            case 'D': {
                if (!y_coords.contains(x)) break;
                auto &coords = y_coords[x];
                for (auto iter = std::prev(coords.upper_bound(y)); *iter >= ny && iter != coords.begin(); iter--) {
                    if (*iter < COORD_MIN || *iter > COORD_MAX) continue;
                    erase_coords.emplace_back(x, *iter);
                }
                break;
            }

            case 'R': {
                if (!x_coords.contains(y)) break;
                auto &coords = x_coords[y];
                for (auto iter = coords.lower_bound(x); *iter <= nx && iter != coords.end(); iter++) {
                    if (*iter < COORD_MIN || *iter > COORD_MAX) continue;
                    erase_coords.emplace_back(*iter, y);
                }
                break;
            }

            case 'L': {
                if (!x_coords.contains(y)) break;
                auto &coords = x_coords[y];
                for (auto iter = std::prev(coords.upper_bound(x)); *iter >= nx && iter != coords.begin(); iter--) {
                    if (*iter < COORD_MIN || *iter > COORD_MAX) continue;
                    erase_coords.emplace_back(*iter, y);
                }
                break;
            }

            default:
                throw std::invalid_argument("Invalid d");
        }

        for (const auto &[xi, yi] : erase_coords) {
            x_coords[yi].erase(xi);
            y_coords[xi].erase(yi);
            ans++;
        }

        x = nx, y = ny;
    }

    std::cout << x << ' ' << y << ' ' << ans << std::endl;
    return 0;
}