#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

void solve() {
    constexpr int NA = -1;

    int n, c;
    std::cin >> n >> c;
    c--;

    std::vector<std::string> s(n);
    for (auto &si : s) std::cin >> si;

    std::vector<int> bottommost_walls(n, NA);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '.') continue;
            if (bottommost_walls[j] != NA) continue;
            bottommost_walls[j] = i;
        }
    }

    std::vector is_reachable(n, std::vector<int>(n, NA));
    std::queue<std::pair<int, int>> que;
    is_reachable[n - 1][c] = true;
    que.emplace(n - 1, c);

    while (!que.empty()) {
        const auto [i, j] = que.front();
        que.pop();

        for (int dj = -1; dj <= 1; dj++) {
            const auto nj = j + dj;
            const auto ni = i - 1;
            if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
            if (is_reachable[ni][nj] != NA) continue;
            if (s[ni][nj] == '.') {
                is_reachable[ni][nj] = true;
                if (ni > 0) que.emplace(ni, nj);
            }
            if (s[ni][nj] == '#') {
                if (bottommost_walls[nj] != ni) {
                    is_reachable[ni][nj] = false;
                    continue;
                }
                for (int di = 0; ni + di >= 0; di--) is_reachable[ni + di][nj] = true, que.emplace(ni + di, nj);
            }
        }
    }

    for (int j = 0; j < n; j++) std::cout << (is_reachable[0][j] == true ? 1 : 0);
    std::cout << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}
