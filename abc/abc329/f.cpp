#include <iostream>
#include <set>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<std::set<int>> boxes(n);
    for (int i = 0; i < n; i++) {
        int c;
        std::cin >> c;
        boxes[i].insert(c);
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;

        if (boxes[a].size() > boxes[b].size()) {
            boxes[a].merge(boxes[b]);
            boxes[b].clear();
            std::swap(boxes[a], boxes[b]);
        } else {
            boxes[b].merge(boxes[a]);
            boxes[a].clear();
        }
        std::cout << boxes[b].size() << std::endl;
    }
    return 0;
}