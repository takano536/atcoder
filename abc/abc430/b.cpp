#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    for (auto &si : s) std::cin >> si;

    std::set<std::vector<std::string>> grids;
    for (int si = 0; si < n - m + 1; si++) {
        for (int sj = 0; sj < n - m + 1; sj++) {
            std::vector<std::string> grid(m);
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    grid[i] += s[si + i][sj + j];
                }
            }
            grids.insert(grid);
        }
    }

    std::cout << grids.size() << std::endl;
    return 0;
}