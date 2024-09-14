#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    int mg;
    std::cin >> mg;
    std::set<std::pair<int, int>> g_edges;
    for (int i = 0; i < mg; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        g_edges.insert({u, v});
        g_edges.insert({v, u});
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

    std::vector a(n, std::vector<int>(n));
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int cost;
            std::cin >> cost;
            a[i][j] = cost, a[j][i] = cost;
        }
    }

    std::vector<int> v(n);
    std::iota(v.begin(), v.end(), 0);
    int ans = 1e9;
    do {
        int cost = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (h_edges.contains({i, j}) && !g_edges.contains({v[i], v[j]})) cost += a[i][j];
                if (!h_edges.contains({i, j}) && g_edges.contains({v[i], v[j]})) cost += a[i][j];
            }
        }
        ans = std::min(cost / 2, ans);
    } while (std::next_permutation(v.begin(), v.end()));

    std::cout << ans << std::endl;
    return 0;
}