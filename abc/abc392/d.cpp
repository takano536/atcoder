#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> dices(n);
    for (auto &dice : dices) {
        int k;
        std::cin >> k;
        for (int i = 0; i < k; i++) {
            int a;
            std::cin >> a;
            dice.push_back(a);
        }
    }

    std::vector prob_dist(n, std::map<int, int>());
    for (int i = 0; i < n; i++) {
        for (const auto &roll : dices[i]) {
            prob_dist[i][roll]++;
        }
    }

    long double ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long double prob = 0;
            for (auto [k, _] : prob_dist[i]) {
                if (!prob_dist[j].contains(k)) continue;
                prob += static_cast<long double>(prob_dist[j][k]) / dices[j].size() * prob_dist[i][k];
            }
            prob /= dices[i].size();
            ans = std::max(ans, prob);
        }
    }

    std::cout << std::fixed << std::setprecision(10) << ans << std::endl;
    return 0;
}