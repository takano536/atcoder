#include <iostream>
#include <set>
#include <stdexcept>
#include <utility>
#include <vector>

int main() {
    int n;
    int tr, tc;
    std::cin >> n >> tr >> tc;
    std::string s;
    std::cin >> s;

    std::set<std::pair<int, int>> bonfires;
    int sr = 0, sc = 0;
    bonfires.insert({sr, sc});

    std::string ans;
    for (const auto &c : s) {
        switch (c) {
            case 'N':
                sr++;
                tr++;
                break;
            case 'S':
                sr--;
                tr--;
                break;
            case 'E':
                sc--;
                tc--;
                break;
            case 'W':
                sc++;
                tc++;
                break;
            default: throw std::runtime_error("invalid input");
        }
        if (!bonfires.contains({sr, sc})) bonfires.insert({sr, sc});
        ans += (bonfires.contains({tr, tc}) ? "1" : "0");
    }

    std::cout << ans << std::endl;
    return 0;
}