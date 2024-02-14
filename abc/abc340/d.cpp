#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int main() {
    const long long INF = 1e18;

    int n;
    std::cin >> n;

    std::vector<std::vector<std::pair<long long, int>>> graph(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, x;
        std::cin >> a >> b >> x;
        graph[i].push_back({a, i + 1});
        graph[i].push_back({b, x - 1});
    }

    std::priority_queue<
        std::pair<long long, int>,
        std::vector<std::pair<long long, int>>,
        std::greater<std::pair<long long, int>>
    > que;
    que.push({0, 0});

    std::vector<long long> dists(n, INF);
    dists[0] = 0;

    while (!que.empty()) {
        auto curr = que.top();
        que.pop();

        if (dists[curr.second] < curr.first) {
            continue;
        }

        dists[curr.second] = curr.first;
        for (const auto &next : graph[curr.second]) {
            auto cost = curr.first + next.first;
            auto to = next.second;
            if (cost < dists[to]) {
                dists[to] = cost;
                que.push({cost, to});
            }
        }
    }

    std::cout << dists[n - 1] << std::endl;
    return 0;
}