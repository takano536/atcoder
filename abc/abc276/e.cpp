#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

int main() {
    constexpr int NA = -1;
    constexpr std::array<std::pair<int, int>, 4> DIRS = {
        std::make_pair(+1, +0),
        std::make_pair(+0, +1),
        std::make_pair(-1, +0),
        std::make_pair(+0, -1),
    };

    int h, w;
    std::cin >> h >> w;

    std::vector<std::string> c(h);
    std::pair<int, int> start_coord;
    for (int i = 0; auto &ci : c) {
        std::cin >> ci;
        if (ci.find('S') != std::string::npos) start_coord = {i, ci.find('S')};
        i++;
    }

    auto exists = [&](const std::pair<int, int> first_coord) {
        const auto [fi, fj] = first_coord;
        const auto [si, sj] = start_coord;
        const std::pair<int, int> bad_dir = {(fi - si) * -1, (fj - sj) * -1};

        std::vector dists(h, std::vector<int>(w, NA));
        dists[fi][fj] = 1;

        std::queue<std::pair<std::pair<int, int>, int>> que;
        que.push({first_coord, 1});

        while (!que.empty()) {

            const auto [curr_coord, dist] = que.front();
            que.pop();

            const auto [ci, cj] = curr_coord;

            for (const auto &dir : DIRS) {
                if (dist == 1 && dir == bad_dir) continue;

                const auto [di, dj] = dir;
                const int ni = ci + di, nj = cj + dj;

                if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                if (c[ni][nj] == '#') continue;
                if (dists[ni][nj] != NA) continue;

                dists[ni][nj] = dist + 1;
                que.push({{ni, nj}, dist + 1});
            }
        }

        return dists[si][sj] >= 4;
    };

    bool is_satisfied = false;
    for (const auto &[di, dj] : DIRS) {
        const auto [si, sj] = start_coord;
        const int fi = si + di, fj = sj + dj;

        if (fi < 0 || fi >= h || fj < 0 || fj >= w) continue;
        if (c[fi][fj] == '#') continue;

        is_satisfied |= exists({fi, fj});
    }

    std::cout << (is_satisfied ? "Yes" : "No") << std::endl;
    return 0;
}