#include <algorithm>
#include <iostream>
#include <vector>

struct Vertex {
    int id;
    std::vector<int> to;
};

int main() {
    const int MAX_K = 20;

    int n, q;
    std::cin >> n >> q;
    std::vector<Vertex> graph(n);
    for (auto &vertex : graph) {
        std::cin >> vertex.id;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        graph[a].to.push_back(b);
        graph[b].to.push_back(a);
    }

    std::vector<std::vector<int>> kth_ids(n);
    auto dfs = [&MAX_K, &graph, &kth_ids](auto &&dfs, int curr, std::vector<bool> &is_visited) -> std::vector<int> {
        std::vector<int> ids = {graph[curr].id};
        is_visited[curr] = true;
        for (const auto &to : graph[curr].to) {
            if (is_visited[to]) {
                continue;
            }
            std::ranges::copy(dfs(dfs, to, is_visited), std::back_inserter(ids));
            std::ranges::sort(ids, std::greater<int>());
            while (ids.size() > MAX_K) {
                ids.pop_back();
            }
        }
        kth_ids[curr] = ids;
        return ids;
    };
    std::vector<bool> is_visited(n);
    dfs(dfs, 0, is_visited);

    for (int query = 0; query < q; query++) {
        int v, k;
        std::cin >> v >> k;
        v--, k--;
        std::cout << kth_ids[v][k] << std::endl;
    }
    return 0;
}