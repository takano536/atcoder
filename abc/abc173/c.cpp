#include <iostream>
#include <string>
#include <vector>

int main() {
    int h, w, k;
    std::cin >> h >> w >> k;

    std::vector<std::string> c(h);
    for (auto &str : c) {
        std::cin >> str;
    }

    int ans = 0;
    for (int bit = 0; bit < (1 << (h + w)); bit++) {
        auto tiles = c;
        for (int i = 0; i < h + w; ++i) {
            if (!(bit & (1 << i))) {
                continue;
            }
            if (i >= h) {
                int curr_line = i - h;
                for (int j = 0; j < h; j++) {
                    tiles[j][curr_line] = ' ';
                }
            } else {
                for (int j = 0; j < w; j++) {
                    tiles[i][j] = ' ';
                }
            }
        }

        int black_num = 0;
        for (const auto &str : tiles) {
            for (const auto &chr : str) {
                black_num += static_cast<int>(chr == '#');
            }
        }
        ans += static_cast<int>(black_num == k);
    }

    std::cout << ans << std::endl;
    return 0;
}