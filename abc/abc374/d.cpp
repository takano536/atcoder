#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    int n, s, t;
    std::cin >> n >> s >> t;

    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> lines(n);
    for (auto &[si, gi] : lines) {
        auto &[a, b] = si;
        auto &[c, d] = gi;
        std::cin >> a >> b >> c >> d;
    }

    std::ranges::sort(lines);

    long double ans = 1e18;
    do {
        for (int bit = 0; bit < (1 << n); bit++) {
            long double time = 0;
            auto curr_lines = lines;
            for (int i = 0; i < n; i++) {
                if (bit & (1 << i)) std::swap(curr_lines[i].first, curr_lines[i].second);
            }
            std::pair<int, int> curr_coored = {0, 0};
            for (const auto &[si, gi] : curr_lines) {
                auto [a, b] = si;
                auto [c, d] = gi;

                int x_diff = a - curr_coored.first;
                int y_diff = b - curr_coored.second;
                time += std::sqrt(x_diff * x_diff + y_diff * y_diff) / s;

                x_diff = c - a;
                y_diff = d - b;
                time += std::sqrt(x_diff * x_diff + y_diff * y_diff) / t;

                curr_coored = {c, d};
            }
            ans = std::min(ans, time);
        }
    } while (std::next_permutation(lines.begin(), lines.end()));

    std::printf("%.10Lf\n", ans);
    return 0;
}