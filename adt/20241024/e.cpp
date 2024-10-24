#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

int main() {
    constexpr auto INF = std::numeric_limits<long long>::max();

    int n;
    std::cin >> n;

    int mg;
    std::cin >> mg;
    std::set<std::pair<int, int>> g_edges;
    for (int i = 0; i < mg; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        g_edges.insert({a, b});
        g_edges.insert({b, a});
    }

    int mh;
    std::cin >> mh;
    std::set<std::pair<int, int>> h_edges;
    for (int i = 0; i < mh; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        h_edges.insert({a, b});
        h_edges.insert({b, a});
    }

    std::vector costs(n, std::vector<int>(n));
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int cost;
            std::cin >> cost;
            costs[i][j] = cost;
            costs[j][i] = cost;
        }
    }

    long long ans = INF;
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    do {
        long long cost = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g_edges.contains({p[i], p[j]}) && !h_edges.contains({i, j})) cost += costs[i][j];
                if (!g_edges.contains({p[i], p[j]}) && h_edges.contains({i, j})) cost += costs[i][j];
            }
        }
        ans = std::min(cost / 2, ans);
    } while (std::ranges::next_permutation(p).found);

    std::cout << ans << std::endl;
    return 0;
}