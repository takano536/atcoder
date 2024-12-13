#include <iostream>
#include <string>
#include <vector>

int main() {
    int h, w, d;
    std::cin >> h >> w >> d;

    std::vector<std::string> s(h);
    for (auto &si : s) std::cin >> si;

    auto count = [&](int i1, int j1, int i2, int j2) {
        std::vector<std::vector<bool>> has_visited(h, std::vector<bool>(w));
        int ret = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (s[i][j] == '#') continue;
                if (has_visited[i][j]) continue;
                int dist1 = std::abs(i - i1) + std::abs(j - j1);
                int dist2 = std::abs(i - i2) + std::abs(j - j2);
                if (dist1 > d && dist2 > d) continue;
                has_visited[i][j] = true;
                ret++;
            }
        }
        return ret;
    };

    int ans = 0;
    for (int i1 = 0; i1 < h; i1++) {
        for (int j1 = 0; j1 < w; j1++) {
            for (int i2 = 0; i2 < h; i2++) {
                for (int j2 = 0; j2 < w; j2++) {
                    if (i1 == i2 && j1 == j2) continue;
                    if (s[i1][j1] == '#' || s[i2][j2] == '#') continue;
                    ans = std::max(ans, count(i1, j1, i2, j2));
                }
            }
        }
    }

    std::cout << ans << std::endl;
    return 0;
}