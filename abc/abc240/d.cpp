#include <iostream>
#include <utility>
#include <vector>

int main() {
    const int NA = 0;

    int n;
    std::cin >> n;

    std::vector<int> pipe = {NA};
    std::vector<std::pair<int, int>> duplicate_nums = {{NA, NA}};
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        pipe.push_back(a);
        if (duplicate_nums.back().first != NA && duplicate_nums.back().first == a) {
            duplicate_nums.back().second++;
            if (duplicate_nums.back().second == duplicate_nums.back().first) {
                while (duplicate_nums.back().second > 0) {
                    pipe.pop_back();
                    duplicate_nums.back().second--;
                }
                duplicate_nums.pop_back();
            }
        } else {
            duplicate_nums.push_back({a, 1});
        }
        std::cout << pipe.size() - 1 << std::endl;
    }
    return 0;
}