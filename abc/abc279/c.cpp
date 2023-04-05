#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    int h, w;
    std::cin >> h >> w;

    std::vector<std::string> s(h), t(h);
    for (auto &str : s) {
        std::cin >> str;
    }
    for (auto &str : t) {
        std::cin >> str;
    }

    std::map<std::string, int> s_map, t_map;
    for (int i = 0; i < w; i++) {
        std::string s_str, t_str;
        for (int j = 0; j < h; j++) {
            s_str += s[j][i];
            t_str += t[j][i];
        }
        s_map[s_str]++;
        t_map[t_str]++;
    }

    bool satisfies = true;
    for (const auto &[key, value] : s_map) {
        if (t_map[key] != value) {
            satisfies = false;
        }
    }

    std::cout << (satisfies ? "Yes" : "No") << std::endl;
    return 0;
}