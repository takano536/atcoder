#include <iostream>
#include <string>
#include <vector>

int main() {
    int h, w;
    std::cin >> h >> w;

    std::vector<std::string> s(h);
    for (auto &str : s) {
        std::cin >> str;
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') {
                continue;
            }

            if (s[i].find('#') == std::string::npos) {
                continue;
            }

            std::string str;
            for (int ii = 0; ii < h; ii++) {
                str += s[ii][j];
            }
            if (str.find('#') == std::string::npos) {
                continue;
            }

            if (s[i][j] == '.') {
                std::cout << i + 1 << ' ' << j + 1 << std::endl;
                return 0;
            }
        }
    }
    return 0;
}