#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> cnts(n + 1);
    std::set<std::pair<int, int>> que;
    for (int i = 0; i < m; i++) {
        int a;
        std::cin >> a;
        if (que.contains({cnts[a], -a})) {
            que.erase({cnts[a], -a});
            que.insert({cnts[a] + 1, -a});
        } else {
            que.insert({1, -a});
        }
        cnts[a]++;
        std::cout << -que.rbegin()->second << std::endl;
    }

    return 0;
}