#include <algorithm>
#include <iostream>
#include <vector>

void dfs(std::vector<std::pair<std::vector<int>, int>> &tree, int curr) {
    for (const auto &next : tree[curr].first) {
        tree[next].second = std::max(tree[curr].second - 1, tree[next].second);
        dfs(tree, next);
    }
    return;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> p(n - 1);
    for (auto &input : p) {
        std::cin >> input;
        input--;
    }

    std::vector<int> x(m), y(m);
    for (int i = 0; i < m; i++) {
        std::cin >> x[i] >> y[i];
        x[i]--;
    }

    std::vector<std::pair<std::vector<int>, int>> tree(n);
    for (int i = 0; i < n; i++) {
        tree[i].second = -1;
    }
    for (int i = 0; i < n - 1; i++) {
        tree[p[i]].first.push_back(i + 1);
    }
    for (int i = 0; i < m; i++) {
        tree[x[i]].second = std::max(y[i], tree[x[i]].second);
    }

    dfs(tree, 0);

    int ans = 0;
    for (const auto &[children, generation] : tree) {
        if (generation >= 0) {
            ans++;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}