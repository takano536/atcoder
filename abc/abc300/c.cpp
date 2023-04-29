#include <iostream>
#include <string>
#include <vector>

int count(const std::vector<std::string> &c, int h, int w, int n) {
    int ret = 0;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (c[i][j] != '#') {
                continue;
            }

            bool satisfies = true;
            for (int d = 1; d <= n; d++) {
                if (i + d >= h || j + d >= w || i - d < 0 || j - d < 0) {
                    satisfies = false;
                    break;
                }
                if (c[i + d][j + d] != '#' || c[i + d][j - d] != '#' || c[i - d][j + d] != '#' ||
                    c[i - d][j - d] != '#') {
                    satisfies = false;
                }

                if (i + n + 1 >= h || j + n + 1 >= w || i - n - 1 < 0 || j - n - 1 < 0) {
                    continue;
                }
                if (c[i + n + 1][j + n + 1] != '.' && c[i + n + 1][j - n - 1] != '.' &&
                    c[i - n - 1][j + n + 1] != '.' && c[i - n - 1][j - n - 1] != '.') {
                    satisfies = false;
                }
            }
            ret += static_cast<int>(satisfies);
        }
    }
    return ret;
}

int main() {
    int h, w;
    std::cin >> h >> w;
    std::vector<std::string> c(h);

    for (auto &str : c) {
        std::cin >> str;
    }

    int n = std::min(h, w);
    for (int i = 1; i <= n; i++) {
        std::cout << count(c, h, w, i) << ' ';
    }
    std::cout << std::endl;
    return 0;
}