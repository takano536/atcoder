#include <iostream>
#include <set>
#include <tuple>
#include <vector>

#include <atcoder/dsu>

int main() {
    int n, m;
    std::cin >> n >> m;

    atcoder::dsu graph(n);
    std::vector<std::tuple<int, int, int>> non_bridges;

    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;

        if (graph.same(a, b)) {
            non_bridges.emplace_back(a, b, i);
            continue;
        }

        graph.merge(a, b);
    }

    std::set<int> leaders;
    for (int i = 0; i < n; i++) leaders.insert(graph.leader(i));

    std::cout << leaders.size() - 1 << std::endl;

    while (leaders.size() > 1) {
        const auto &[to, _, i] = non_bridges.back();
        non_bridges.pop_back();
        leaders.erase(graph.leader(to));

        const auto from = *leaders.begin();
        leaders.erase(from);

        graph.merge(to, from);
        leaders.insert(graph.leader(to));

        std::cout << i + 1 << ' ' << to + 1 << ' ' << from + 1 << std::endl;
    }

    return 0;
}