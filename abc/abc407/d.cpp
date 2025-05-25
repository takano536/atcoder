#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
    int h, w;
    std::cin >> h >> w;

    std::vector a(h, std::vector<long long>(w));
    long long score = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::cin >> a[i][j], score ^= a[i][j];
        }
    }

    auto dfs = [&a, &h, &w](auto &&f, const int i, const int j, const long long score, std::set<std::pair<int, int>> &masked_ids) -> long long {
        const auto nj = (j + 1) % w;
        const auto ni = (nj == 0 ? i + 1 : i);

        if (ni >= h) return score;

        long long max_score = score;
        const bool placeable = !masked_ids.contains({i, j});
        const bool placeable_vertically = placeable && !masked_ids.contains({i + 1, j});
        const bool placeable_horizontally = placeable && !masked_ids.contains({i, j + 1});
        if (i + 1 < h && placeable_vertically) {
            masked_ids.insert({i, j});
            masked_ids.insert({i + 1, j});
            max_score = std::max(max_score, f(f, ni, nj, score ^ a[i][j] ^ a[i + 1][j], masked_ids));
            masked_ids.erase({i, j});
            masked_ids.erase({i + 1, j});
        }
        if (j + 1 < w && placeable_horizontally) {
            masked_ids.insert({i, j});
            masked_ids.insert({i, j + 1});
            max_score = std::max(max_score, f(f, ni, nj, score ^ a[i][j] ^ a[i][j + 1], masked_ids));
            masked_ids.erase({i, j});
            masked_ids.erase({i, j + 1});
        }
        return std::max(max_score, f(f, ni, nj, score, masked_ids));
    };

    std::set<std::pair<int, int>> masked_ids;
    std::cout << dfs(dfs, 0, 0, score, masked_ids) << std::endl;
    return 0;
}