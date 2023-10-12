#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::map<std::string, int> ids;
    std::size_t max_id = 0;
    std::vector<std::string> s(n), t(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i] >> t[i];
        if (!ids.contains(s[i])) {
            ids[s[i]] = max_id++;
        }
        if (!ids.contains(t[i])) {
            ids[t[i]] = max_id++;
        }
    }

    std::vector<std::vector<int>> graph(max_id);
    std::vector<int> indegrees(max_id);
    for (int i = 0; i < n; i++) {
        graph[ids[s[i]]].push_back(ids[t[i]]);
        indegrees[ids[t[i]]]++;
    }

    std::queue<int> que;
    for (std::size_t vertex = 0; vertex < max_id; vertex++) {
        if (indegrees[vertex] == 0) {
            que.push(vertex);
        }
    }

    std::vector<int> sorted_vertexs;
    while (!que.empty()) {
        auto curr_vertex = que.front();
        que.pop();

        sorted_vertexs.push_back(curr_vertex);
        for (auto next_vertex : graph[curr_vertex]) {
            indegrees[next_vertex]--;
            if (indegrees[next_vertex] == 0) {
                que.push(next_vertex);
            }
        }
    }

    std::cout << (sorted_vertexs.size() == max_id ? "Yes" : "No") << std::endl;
}