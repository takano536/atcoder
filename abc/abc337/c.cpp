#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> graph(n);
    int start = -1;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        if (a == -1) {
            start = i;
            continue;
        }
        graph[a - 1].push_back(i);
    }

    std::vector<int> ans;
    ans.push_back(start);
    while (ans.size() < static_cast<std::size_t>(n)) {
        ans.push_back(graph[ans.back()][0]);
    }

    for (int i = 0; i < n; i++) {
        std::cout << ans[i] + 1 << ' ';
    }
    std::cout << std::endl;
    return 0;
}