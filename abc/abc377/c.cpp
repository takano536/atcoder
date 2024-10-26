#include <array>
#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    auto pair2int = [&n](int i, int j) -> long long { return static_cast<long long>(i) * n + j; };

    constexpr std::array<std::pair<int, int>, 8> VECS = {
        std::make_pair(-2, 1),
        std::make_pair(-1, 2),
        std::make_pair(1, 2),
        std::make_pair(2, 1),
        std::make_pair(2, -1),
        std::make_pair(1, -2),
        std::make_pair(-1, -2),
        std::make_pair(-2, -1),
    };

    std::set<long long> bad_coords;
    for (int _ = 0; _ < m; _++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;

        bad_coords.insert(pair2int(a, b));

        for (const auto &[di, dj] : VECS) {
            int ni = a + di;
            int nj = b + dj;
            if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
            bad_coords.insert(pair2int(ni, nj));
        }
    }

    std::cout << static_cast<long long>(n) * n - bad_coords.size() << std::endl;
    return 0;
}