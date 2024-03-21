#include <algorithm>
#include <iostream>
#include <vector>

#include <atcoder/dsu>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> indegrees(n);
    atcoder::dsu union_find(n);
    bool is_satisfied = true;
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        if (union_find.same(a, b)) {
            is_satisfied = false;
        }
        union_find.merge(a, b);
        indegrees[a]++;
        indegrees[b]++;
        if (indegrees[a] > 2 || indegrees[b] > 2) {
            is_satisfied = false;
        }
    }

    std::cout << (is_satisfied ? "Yes" : "No") << std::endl;
    return 0;
}