#include <iostream>
#include <set>
#include <vector>

int main() {
    int h, w, n;
    std::cin >> h >> w >> n;

    std::vector<std::set<int>> h_counts(h), w_counts(w);
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        h_counts[x].insert(y);
        w_counts[y].insert(x);
    }

    int q;
    std::cin >> q;
    while (q--) {
        int op, coord;
        std::cin >> op >> coord;
        coord--;

        if (op == 1) {
            std::cout << h_counts[coord].size() << std::endl;
            for (const auto &y : h_counts[coord]) w_counts[y].erase(coord);
            h_counts[coord].clear();
        } else {
            std::cout << w_counts[coord].size() << std::endl;
            for (const auto &x : w_counts[coord]) h_counts[x].erase(coord);
            w_counts[coord].clear();
        }
    }

    return 0;
}