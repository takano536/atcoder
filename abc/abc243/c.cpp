#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::tuple<int, int, int>> coords(n);
    for (int i = 0; auto &[y, x, id] : coords) {
        std::cin >> x >> y;
        id = i++;
    }
    std::string s;
    std::cin >> s;

    std::ranges::sort(coords);
    int prev_y = std::get<0>(coords[0]);
    const int NA = -1;
    int left_x = NA;
    int right_x = NA;
    for (const auto &[y, x, i] : coords) {
        if (y != prev_y) {
            left_x = NA;
            right_x = NA;
        }
        (s[i] == 'L' ? left_x : right_x) = x;
        prev_y = y;
        if (left_x != NA && right_x != NA && left_x > right_x) {
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }
    std::cout << "No" << std::endl;
    return 0;
}