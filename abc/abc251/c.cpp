#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::set<std::string> used_key;
    std::vector<std::pair<int, int>> scores;
    for (int i = 0; i < n; i++) {
        std::string s;
        int t;
        std::cin >> s >> t;
        if (used_key.contains(s)) {
            continue;
        }
        used_key.insert(s);
        scores.emplace_back(t, -i);
    }

    auto ans = std::ranges::max_element(scores);
    std::cout << -ans->second + 1 << std::endl;
    return 0;
}