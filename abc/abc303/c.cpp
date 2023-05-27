#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>

int main() {
    const std::map<char, std::pair<int, int>> DIRECTION = {
        {'L', {-1, 0}}, 
        {'R', {1, 0}}, 
        {'U', {0, 1}}, 
        {'D', {0, -1}}
    };

    int n, m, h, k;
    std::cin >> n >> m >> h >> k;
    std::string s;
    std::cin >> s;

    std::set<std::pair<int, int>> items;
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        items.insert({x, y});
    }

    std::pair<int, int> pos = {0, 0};
    for (int i = 0; i < n; i++) {
        pos.first += DIRECTION.at(s[i]).first;
        pos.second += DIRECTION.at(s[i]).second;
        h--;

        if (h < 0) {
            std::cout << "No" << std::endl;
            return 0;
        }
        if (h < k && items.find(pos) != items.end()) {
            h = k;
            items.erase(pos);
            continue;
        }
    }

    std::cout << "Yes" << std::endl;
}