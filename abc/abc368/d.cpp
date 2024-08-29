#include <iostream>
#include <set>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector graph(n, std::set<int>());
    std::vector<int> indegrees(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        graph[a].insert(b);
        graph[b].insert(a);
        indegrees[a]++;
        indegrees[b]++;
    }

    std::set<int> v;
    for (int i = 0; i < k; i++) {
        int vi;
        std::cin >> vi;
        vi--;
        v.insert(vi);
    }

    std::vector<int> que;
    for (int i = 0; i < n; i++) {
        if (v.contains(i)) continue;
        if (indegrees[i] > 1) continue;
        que.push_back(i);
    }

    int ans = graph.size();
    while (!que.empty()) {
        const auto i = que.back();
        que.pop_back();

        if (v.contains(i)) continue;
        auto rm_vertices = graph[i];
        graph[i] = std::set<int>();
        ans--;
        for (const auto &rm_vertex : rm_vertices) {
            indegrees[rm_vertex]--;
            graph[rm_vertex].erase(i);
            if (graph[rm_vertex].size() == 1) que.push_back(rm_vertex);
        }
    }

    std::cout << ans << std::endl;
    return 0;
}