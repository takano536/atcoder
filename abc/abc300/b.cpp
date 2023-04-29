#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> shift_h(const std::vector<std::string> &s, int h, int w) {
    auto ret = s;
    for (int i = 0; i < h - 1; i++) {
        ret[i] = ret[i + 1];
    }
    ret[h - 1] = s[0];
    return ret;
}

std::vector<std::string> shift_w(const std::vector<std::string> &s, int h, int w) {
    auto ret = s;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w - 1; j++) {
            ret[i][j] = ret[i][j + 1];
        }
        ret[i][w - 1] = s[i][0];
    }
    return ret;
}

bool satisfies(const std::vector<std::string> &a, const std::vector<std::string> &b, int h, int w) {
    bool satisfies = true;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] != b[i][j]) {
                satisfies = false;
            }
        }
    }
    return satisfies;
}

int main() {
    int h, w;
    std::cin >> h >> w;
    std::vector<std::string> a(h), b(h);

    for (auto &str : a) {
        std::cin >> str;
    }
    for (auto &str : b) {
        std::cin >> str;
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w - 1; j++) {
            auto ret = a;
            for (int ii = 0; ii < i; ii++) {
                ret = shift_h(ret, h, w);
            }
            for (int jj = 0; jj < j; jj++) {
                ret = shift_w(ret, h, w);
            }
            if (satisfies(ret, b, h, w)) {
                std::cout << "Yes" << std::endl;
                return 0;
            }
        }
    }

    std::cout << "No" << std::endl;
    return 0;
}