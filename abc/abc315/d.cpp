#include <array>
#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
    constexpr int N = 'z' - 'a' + 1;

    int h, w;
    std::cin >> h >> w;
    std::vector hol_nums(h, std::array<int, N>());
    std::vector ver_nums(w, std::array<int, N>());
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c;
            std::cin >> c;
            const int ci = c - 'a';
            hol_nums[i][ci]++, ver_nums[j][ci]++;
        }
    }

    int curr_h = h;
    int curr_w = w;
    std::vector<bool> has_removed(h + w);
    for (int _ = 0; _ < h + w; _++) {
        for (int ci = 0; ci < N; ci++) {
            std::set<int> que;
            for (int i = 0; i < h; i++) {
                if (has_removed[i]) continue;
                if (hol_nums[i][ci] >= 2 && hol_nums[i][ci] == curr_w) que.insert(i);
            }
            for (int j = 0; j < w; j++) {
                if (has_removed[h + j]) continue;
                if (ver_nums[j][ci] >= 2 && ver_nums[j][ci] == curr_h) que.insert(h + j);
            }
            for (const auto &i : que) {
                if (i >= h) continue;
                has_removed[i] = true;
                for (int j = 0; j < w; j++) ver_nums[j][ci]--;
                curr_h--;
            }
            for (const auto &j : que) {
                if (j < h) continue;
                has_removed[j] = true;
                for (int i = 0; i < h; i++) hol_nums[i][ci]--;
                curr_w--;
            }
        }
    }

    std::cout << curr_h * curr_w << std::endl;
    return 0;
}