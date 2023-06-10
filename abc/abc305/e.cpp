#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    std::priority_queue<std::pair<int, int>> heap;

    for (int i = 0; i < k; i++) {
        int p, h;
        std::cin >> p >> h;
        p--;
        heap.push(std::make_pair(h, p));
    }

    std::vector<int> dists(n, -1);

    while (!heap.empty()) {
        auto [h, p] = heap.top();
        heap.pop();

        if (dists[p] != -1) {
            continue;
        }

        dists[p] = h;

        for (auto next : graph[p]) {
            if (dists[next] >= h - 1) {
                continue;
            }
            dists[next] = std::min(dists[next], h - 1);
            heap.push(std::make_pair(h - 1, next));
        }
    }

    std::vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (dists[i] != -1) {
            ans.push_back(i + 1);
        }
    }

    std::cout << ans.size() << std::endl;
    for (const auto &v : ans) {
        std::cout << v << ' ';
    }
    std::cout << std::endl;
}