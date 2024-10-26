#include <iostream>
#include <string>
#include <vector>

int main() {
    constexpr int N = 8;
    std::vector<std::string> s(N);
    for (auto &si : s) std::cin >> si;

    auto rotate_90 = [](std::vector<std::string> &s) {
        std::vector<std::string> t(N, std::string(N, '.'));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                t[j][N - 1 - i] = s[i][j];
            }
        }
        s = t;
    };

    for (auto &si : s) {
        if (si.find('#') != std::string::npos) {
            for (int i = 0; i < N; i++) {
                if (si[i] == '.') si[i] = '$';
            }
        }
    }

    rotate_90(s);

    for (auto &si : s) {
        if (si.find('#') != std::string::npos) {
            for (int i = 0; i < N; i++) {
                if (si[i] == '.') si[i] = '$';
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (s[i][j] == '.') ans++;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}