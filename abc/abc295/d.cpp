#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() {
    std::string s;
    std::cin >> s;

    std::vector<bool> is_odd_count(10);
    std::map<std::vector<bool>, long long> count_map;

    count_map[is_odd_count]++;
    for (const auto &c : s) {
        int curr_num = std::stoi(std::string({c}));
        is_odd_count[curr_num] = (is_odd_count[curr_num] + 1) % 2;
        count_map[is_odd_count]++;
    }

    long long ans = 0;
    for (const auto &mp : count_map) {
        ans += mp.second * (mp.second - 1) / 2;
    }

    std::cout << ans << std::endl;
    return 0;
}