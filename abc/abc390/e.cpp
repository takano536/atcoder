#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    constexpr int VIT_NUM = 3;

    int n, x;
    std::cin >> n >> x;

    std::vector<std::vector<std::pair<int, int>>> vitamins(VIT_NUM);
    for (int i = 0; i < n; i++) {
        int v, a, c;
        std::cin >> v >> a >> c;
        v--;
        vitamins[v].emplace_back(a, c);
    }

    auto calc = [vitamins, x](int v) {
        const auto vits = vitamins[v];
        const int n = vits.size();
        std::vector<int> ret(x + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = x; j >= 0; j--) {
                const auto [ai, ci] = vits[i - 1];
                if (j + ci > x) continue;
                ret[j + ci] = std::max(ret[j + ci], ret[j] + ai);
            }
        }
        return ret;
    };

    std::vector<std::vector<int>> vit_table(VIT_NUM);
    for (int i = 0; i < VIT_NUM; i++) vit_table[i] = calc(i);

    int ans = 0;
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= x; j++) {
            if (i + j > x) continue;
            const int k = x - i - j;
            ans = std::max(ans, std::min({vit_table[0][i], vit_table[1][j], vit_table[2][k]}));
        }
    }
    std::cout << ans << std::endl;
    return 0;
}