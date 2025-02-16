#include <iostream>
#include <set>
#include <utility>
#include <vector>

int main() {
    int INF = 1e9;

    int n, w;
    std::cin >> n >> w;

    std::vector<std::set<std::pair<int, int>>> field(w);
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        x--;
        field[x].insert({y, i});
    }

    std::vector<long long> delete_time(n, INF);
    while (true) {
        bool is_empty = false;
        int max_y = 0;
        for (int i = 0; i < w; i++) {
            if (field[i].empty()) {
                is_empty = true;
                break;
            }
            max_y = std::max(max_y, field[i].begin()->first);
        }
        if (is_empty) break;

        for (int i = 0; i < w; i++) {
            delete_time[field[i].begin()->second] = max_y;
            field[i].erase(field[i].begin());
        }
    }

    int q;
    std::cin >> q;
    while (q--) {
        int t, a;
        std::cin >> t >> a;
        a--;
        std::cout << (t < delete_time[a] ? "Yes" : "No") << std::endl;
    }
    return 0;
}