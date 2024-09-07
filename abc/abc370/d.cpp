#include <iostream>
#include <set>
#include <utility>
#include <vector>

int main() {
    int h, w, q;
    std::cin >> h >> w >> q;

    int ans = h * w;
    std::vector<std::set<int>> wall_h(h), wall_w(w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            wall_h[i].insert(j);
            wall_w[j].insert(i);
        }
    }

    while (q--) {
        int i, j;
        std::cin >> i >> j;
        i--, j--;

        if (wall_h[i].contains(j)) {

            wall_h[i].erase(j);
            wall_w[j].erase(i);
            ans--;

        } else {

            std::vector<std::pair<int, int>> erase_coords;

            auto r_iter = wall_h[i].lower_bound(j);
            if (r_iter == wall_h[i].end()) {
                if (wall_h[i].size() > 0) erase_coords.emplace_back(i, *std::prev(r_iter));
            } else if (r_iter == wall_h[i].begin()) {
                erase_coords.emplace_back(i, *r_iter);
            } else {
                auto l_iter = std::prev(r_iter);
                erase_coords.emplace_back(i, *l_iter);
                erase_coords.emplace_back(i, *r_iter);
            }

            r_iter = wall_w[j].lower_bound(i);
            if (r_iter == wall_w[j].end()) {
                if (wall_w[j].size() > 0) erase_coords.emplace_back(*std::prev(r_iter), j);
            } else if (r_iter == wall_w[j].begin()) {
                erase_coords.emplace_back(*r_iter, j);
            } else {
                auto l_iter = std::prev(r_iter);
                erase_coords.emplace_back(*l_iter, j);
                erase_coords.emplace_back(*r_iter, j);
            }

            for (auto [i, j] : erase_coords) {
                wall_h[i].erase(j);
                wall_w[j].erase(i);
                ans--;
            }
        }
    }

    std::cout << ans << std::endl;
    return 0;
}