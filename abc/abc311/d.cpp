#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    const std::vector<std::pair<int, int>> DIR = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    auto dfs = [&](auto dfs, std::pair<int, int> curr, int cnt, std::pair<int, int> dir, std::vector<std::vector<bool>> &visited, std::vector<std::vector<bool>> &stop_pos) -> void {
        visited[curr.first][curr.second] = true;
        auto next = curr;
        while (s[next.first + dir.first][next.second + dir.second] != '#') {
            next.first += dir.first;
            next.second += dir.second;
            visited[next.first][next.second] = true;
        }
        if (stop_pos[next.first][next.second]) {
            return;
        }
        stop_pos[next.first][next.second] = true;
        if (next == curr) {
            return;
        }
        for (const auto &d : DIR) {
            if (next.first + d.first < 0 || next.first + d.first >= n || next.second + d.second < 0 || next.second + d.second >= m) {
                continue;
            }
            if (s[next.first + d.first][next.second + d.second] == '#') {
                continue;
            }
            dfs(dfs, next, cnt, d, visited, stop_pos);
        }
        return;
    };

    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m));
    for (const auto &d : DIR) {
        std::vector<std::vector<bool>> stop_pos(n, std::vector<bool>(m));
        dfs(dfs, {1, 1}, 1, d, visited, stop_pos);
    }

    int ans = 0;
    for (const auto &v : visited) {
        ans += std::count(v.begin(), v.end(), true);
    }
    std::cout << ans << std::endl;
    return 0;
}