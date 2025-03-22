#include <iostream>
#include <map>
#include <vector>

int main() {
    constexpr int NA = -1;

    int n;
    std::cin >> n;

    std::map<int, std::vector<int>> cnts;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        cnts[a].push_back(i + 1);
    }

    int max_num = NA;
    for (const auto &[num, indexes] : cnts) {
        if (indexes.size() >= 2) continue;
        max_num = std::max(max_num, num);
    }

    std::cout << (max_num == NA ? -1 : *cnts[max_num].begin()) << std::endl;
    return 0;
}