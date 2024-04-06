#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

int main() {
    int h, w;
    std::cin >> h >> w;
    std::vector<std::string> a(h);
    std::pair<int, int> start, goal;
    for (int i = 0; auto &ai : a) {
        std::cin >> ai;
        if (ai.find('S') != std::string::npos) {
            start = std::make_pair(i, ai.find('S'));
        }
        if (ai.find('T') != std::string::npos) {
            goal = std::make_pair(i, ai.find('T'));
        }
        i++;
    }

    auto pair2int = [&w](std::pair<int, int> coord) { return coord.first * w + coord.second; };
    auto int2pair = [&w](int i) { return std::make_pair(i / w, i % w); };

    int n;
    std::cin >> n;
    std::map<int, int> medicines;
    for (int i = 0; i < n; i++) {
        int r, c, e;
        std::cin >> r >> c >> e;
        medicines[pair2int({r - 1, c - 1})] = e;
    }

    const std::vector<std::pair<int, int>> DIRS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    std::map<int, std::set<int>> graph;

    auto merge_graph = [&](const std::pair<int, int> start_coord) {
        auto curr_coord = start_coord;
        auto curr_power = medicines[pair2int(curr_coord)];
        std::queue<std::pair<std::pair<int, int>, int>> que;
        que.push({curr_coord, curr_power});
        std::vector<std::vector<int>> dist(h, std::vector<int>(w, -1));
        dist[curr_coord.first][curr_coord.second] = 0;
        while (!que.empty()) {
            auto [curr, power] = que.front();
            que.pop();
            for (const auto &dir : DIRS) {
                auto next = std::make_pair(curr.first + dir.first, curr.second + dir.second);
                if (next.first < 0 || next.first >= h || next.second < 0 || next.second >= w) {
                    continue;
                }
                if (a[next.first][next.second] == '#') {
                    continue;
                }
                if (dist[next.first][next.second] != -1) {
                    continue;
                }
                if (power == 0) {
                    continue;
                }
                if (medicines.contains(pair2int(next))) {
                    graph[pair2int(start_coord)].insert(pair2int(next));
                }
                if (next == goal) {
                    graph[pair2int(start_coord)].insert(pair2int(next));
                }
                if (next == start) {
                    graph[pair2int(start_coord)].insert(pair2int(next));
                }
                dist[next.first][next.second] = dist[curr.first][curr.second] + 1;
                que.push({next, power - 1});
            }
        }
    };

    for (const auto &medicine : medicines) {
        merge_graph(int2pair(medicine.first));
    }

    std::map<int, bool> is_visited;
    bool is_reachable = false;
    auto dfs = [&](auto &&f, int curr) -> void {
        if (is_visited[curr]) {
            return;
        }
        is_visited[curr] = true;
        if (curr == pair2int(goal)) {
            is_reachable = true;
            return;
        }
        for (const auto &next : graph[curr]) {
            f(f, next);
        }
    };
    dfs(dfs, pair2int(start));

    std::cout << (is_reachable ? "Yes" : "No") << std::endl;
    return 0;
}