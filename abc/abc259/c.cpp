#include <iostream>
#include <utility>
#include <vector>

int main() {
    std::string s, t;
    std::cin >> s >> t;

    auto compress = [](const std::string &s) {
        std::vector<std::pair<char, int>> res;
        int cnt = 1;
        char prev = s[0];
        for (std::size_t i = 1; i < s.size(); i++) {
            if (s[i] != prev) {
                res.push_back({prev, cnt});
                prev = s[i];
                cnt = 0;
            }
            cnt++;
        }
        res.push_back({prev, cnt});
        return res;
    };

    auto compressed_s = compress(s);
    auto compressed_t = compress(t);

    if (compressed_s.size() != compressed_t.size()) {
        std::cout << "No" << std::endl;
        return 0;
    }

    bool is_satisfied = true;
    for (std::size_t i = 0; i < compressed_s.size(); i++) {
        auto [si_c, si_cnt] = compressed_s[i];
        auto [ti_c, ti_cnt] = compressed_t[i];

        if (si_c != ti_c) {
            is_satisfied = false;
            break;
        }

        if (si_cnt == ti_cnt) {
            continue;
        }
        if (si_cnt >= 2 && si_cnt < ti_cnt) {
            continue;
        }

        is_satisfied = false;
        break;
    }

    std::cout << (is_satisfied ? "Yes" : "No") << std::endl;
    return 0;
}