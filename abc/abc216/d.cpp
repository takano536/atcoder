#include <iostream>
#include <queue>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector a(m, std::vector<int>());
    std::vector color_idx_table(n, std::vector<int>());
    std::queue<int> discardable_colors;

    for (int i = 0; i < m; i++) {
        int k;
        std::cin >> k;
        for (int j = 0; j < k; j++) {
            int color;
            std::cin >> color;
            color--;
            a[i].push_back(color);
        }
        color_idx_table[a[i].back()].push_back(i);
        if (color_idx_table[a[i].back()].size() == 2) {
            discardable_colors.push(a[i].back());
        }
    }

    int discarded_cnt = 0;
    while (!discardable_colors.empty()) {
        const auto discarding_color = discardable_colors.front();
        discardable_colors.pop();
        discarded_cnt++;

        for (const auto &pipe_idx : color_idx_table[discarding_color]) {
            a[pipe_idx].pop_back();
            if (a[pipe_idx].empty()) {
                continue;
            }
            color_idx_table[a[pipe_idx].back()].push_back(pipe_idx);
            if (color_idx_table[a[pipe_idx].back()].size() == 2) {
                discardable_colors.push(a[pipe_idx].back());
            }
        }
        color_idx_table[discarding_color].clear();
    }

    std::cout << (discarded_cnt == n ? "Yes" : "No") << std::endl;
    return 0;
}