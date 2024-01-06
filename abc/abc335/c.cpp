#include <iostream>
#include <map>
#include <queue>

int main() {
    std::map<char, std::pair<int, int>> DIRS = {
        {'R', {1, 0}},
        {'L', {-1, 0}},
        {'U', {0, 1}},
        {'D', {0, -1}},
    };

    int n, q;
    std::cin >> n >> q;

    std::deque<std::pair<int, int>> parts;
    for (int i = 1; i <= n; i++) {
        parts.push_back(std::make_pair(i, 0));
    }
    for (int i = 0; i < q; i++) {
        int query;
        std::cin >> query;
        if (query == 1) {
            char c;
            std::cin >> c;
            auto head = parts.front();
            parts.pop_back();
            parts.push_front(std::make_pair(head.first + DIRS[c].first, head.second + DIRS[c].second));
        } else {
            int p;
            std::cin >> p;
            std::cout << parts[p - 1].first << " " << parts[p - 1].second << std::endl;
        }
    }
    return 0;
}