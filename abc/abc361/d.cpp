#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>

int main() {
    int n;
    std::cin >> n;

    std::string s, t;
    std::cin >> s >> t;
    s += "..", t += "..";

    std::map<std::string, int> costs;
    costs[s] = 0;
    std::queue<std::pair<std::string, int>> que;
    que.push({s, 0});

    while (!que.empty()) {
        auto [curr, cost] = que.front();
        que.pop();
        int brank_idx = curr.find(".");
        for (int i = 0; i < n + 2 - 1; i++) {
            if (curr[i] == '.' || curr[i + 1] == '.') continue;
            auto next = curr;
            std::swap(next[i], next[brank_idx]);
            std::swap(next[i + 1], next[brank_idx + 1]);
            if (costs.contains(next) && costs[next] <= cost + 1) continue;
            costs[next] = cost + 1;
            que.push({next, cost + 1});
        }
    }

    std::cout << (costs.contains(t) ? costs[t] : -1) << std::endl;
    return 0;
}