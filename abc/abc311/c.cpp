#include <iostream>
#include <unordered_set>
#include <vector>

#include <atcoder/dsu>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    atcoder::dsu dsu(n);

    int start = -1;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
        if (dsu.same(i, a[i])) {
            start = i;
        }
        dsu.merge(i, a[i]);
    }

    std::vector<int> ans;
    std::vector<bool> visited(n);
    int curr = start;
    while (!visited[curr]) {
        ans.push_back(curr);
        visited[curr] = true;
        curr = a[curr];
    }

    std::cout << ans.size() << std::endl;
    for (const auto &v : ans) {
        std::cout << v + 1 << ' ';
    }
    std::cout << std::endl;
    return 0;
}