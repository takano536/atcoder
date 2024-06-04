#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

int main() {
    int h, w;
    std::pair<int, int> coord;
    std::cin >> h >> w >> coord.first >> coord.second;

    int n;
    std::cin >> n;

    std::map<int, std::set<int>> h_walls_asc;
    std::map<int, std::set<int>> w_walls_asc;
    std::map<int, std::set<int>> h_walls_desc;
    std::map<int, std::set<int>> w_walls_desc;
    for (int i = 0; i < n; i++) {
        int r, c;
        std::cin >> r >> c;
        if (!h_walls_asc.contains(r)) {
            h_walls_asc[r].insert(0);
            h_walls_desc[r].insert(0);
            h_walls_asc[r].insert(w + 1);
            h_walls_desc[r].insert(-(w + 1));
        }
        if (!w_walls_asc.contains(c)) {
            w_walls_asc[c].insert(0);
            w_walls_desc[c].insert(0);
            w_walls_asc[c].insert(h + 1);
            w_walls_desc[c].insert(-(h + 1));
        }
        h_walls_asc[r].insert(c);
        w_walls_asc[c].insert(r);
        h_walls_desc[r].insert(-c);
        w_walls_desc[c].insert(-r);
    }

    int q;
    std::cin >> q;
    while (q--) {
        char c;
        int l;
        std::cin >> c >> l;

        auto [i, j] = coord;
        switch (c) {
            case 'U': {
                if (!w_walls_desc.contains(j)) {
                    i = std::max(i - l, 1);
                } else {
                    auto iter = w_walls_desc[j].lower_bound(-i);
                    i = std::max(i - l, (iter != w_walls_desc[j].end() ? -*iter + 1 : 1));
                }
                break;
            }
            case 'D': {
                if (!w_walls_asc.contains(j)) {
                    i = std::min(i + l, h);
                } else {
                    auto iter = w_walls_asc[j].lower_bound(i);
                    i = std::min(i + l, (iter != w_walls_asc[j].end() ? *iter - 1 : h));
                }
                break;
            }
            case 'L': {
                if (!h_walls_desc.contains(i)) {
                    j = std::max(j - l, 1);
                } else {
                    auto iter = h_walls_desc[i].lower_bound(-j);
                    j = std::max(j - l, (iter != h_walls_desc[i].end() ? -*iter + 1 : 1));
                }
                break;
            }
            case 'R': {
                if (!h_walls_asc.contains(i)) {
                    j = std::min(j + l, w);
                } else {
                    auto iter = h_walls_asc[i].lower_bound(j);
                    j = std::min(j + l, (iter != h_walls_asc[i].end() ? *iter - 1 : w));
                }
                break;
            }
        }

        std::cout << i << ' ' << j << std::endl;
        coord = {i, j};
    }
    return 0;
}