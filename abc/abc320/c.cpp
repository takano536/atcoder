#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    int m;
    std::cin >> m;

    std::vector<std::string> s(3);
    for (int i = 0; i < 3; ++i) {
        std::cin >> s[i];
    }

    bool is_possible = false;
    std::vector<char> align_chars;
    for (int c = 0; c <= 9; c++) {
        bool satisfied = true;
        for (int i = 0; i < 3; i++) {
            if (s[i].find(std::to_string(c)) == std::string::npos) {
                satisfied = false;
                break;
            }
        }
        if (satisfied) {
            is_possible = true;
            align_chars.push_back(std::to_string(c)[0]);
        }
    }

    if (!is_possible) {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::ranges::sort(s);

    int ans = 1e9;
    do {
        for (const auto &c : align_chars) {
            int time = 0;
            std::vector<bool> is_stopped(3, false);
            int j = 0;
            while (std::ranges::any_of(is_stopped, [](bool is_stopped) { return !is_stopped; })) {
                for (int i = 0; i < 3; i++) {
                    if (is_stopped[i]) {
                        continue;
                    }
                    if (s[i][j] == c) {
                        is_stopped[i] = true;
                        break;
                    }
                }
                time++;
                j = (j + 1) % m;
            }
            ans = std::min(ans, time);
        }
    } while (std::next_permutation(s.begin(), s.end()));

    std::cout << ans - 1 << std::endl;
    return 0;
}