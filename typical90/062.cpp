#include <iostream>
#include <map>
#include <vector>

int main() {
    int h, w;
    std::cin >> h >> w;

    std::vector p(h, std::vector<int>(w));
    for (auto &vec : p) {
        for (auto &elem : vec) {
            std::cin >> elem;
            elem--;
        }
    }

    int ans = 0;
    for (int bit = 0; bit < (1 << h); bit++) {
        std::vector<int> idxes;
        for (int i = 0; i < h; i++) {
            if (bit & (1 << i)) idxes.push_back(i);
        }

        if (idxes.size() == 0) continue;

        std::map<int, int> cnts;
        int max_cnt = 0;
        for (int j = 0; j < w; j++) {
            if (idxes.size() > 1) {
                bool is_satisfied = true;
                for (auto iter = idxes.begin(); iter != std::prev(idxes.end()); iter++) {
                    if (p[*iter][j] != p[*std::next(iter)][j]) is_satisfied = false;
                }
                if (!is_satisfied) continue;
            }
            cnts[p[idxes[0]][j]] += idxes.size();
            max_cnt = std::max(cnts[p[idxes[0]][j]], max_cnt);
        }
        ans = std::max(ans, max_cnt);
    }

    std::cout << ans << std::endl;
    return 0;
}