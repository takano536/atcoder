#include <iostream>
#include <set>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::set<int>> graph(n);

    for (int i = 0; i < m; i++) {
        std::vector<int> a(n);
        for (auto &num : a) {
            std::cin >> num;
            num--;
        }

        for (int j = 0; j < n - 1; j++) {
            graph[a[j]].insert(a[j + 1]);
            graph[a[j + 1]].insert(a[j]);
        }
    }

    int ans = 0;
    for (const auto &vec : graph) {
        ans += (n - 1) - vec.size();
    }
    ans /= 2;

    std::cout << ans << std::endl;
}