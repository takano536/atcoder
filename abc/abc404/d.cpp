#include <iostream>
#include <numeric>
#include <vector>

int main() {
    constexpr long long INF = 8e18;

    int n, m;
    std::cin >> n >> m;

    std::vector<int> c(n);
    for (auto &ci : c) std::cin >> ci;

    std::vector zoos(n, std::vector<int>());
    for (int i = 0; i < m; i++) {
        int k;
        std::cin >> k;
        for (int j = 0; j < k; j++) {
            int a;
            std::cin >> a;
            a--;
            zoos[a].push_back(i);
        }
    }

    long long ans = INF;
    auto dfs = [&](auto &&f, const int curr_zoo, const long long cost, std::vector<int> &saw_counts) {
        if (curr_zoo == n) {
            for (const auto &saw_count : saw_counts) {
                if (saw_count < 2) return;
            }
            ans = std::min(cost, ans);
            return;
        }
        f(f, curr_zoo + 1, cost, saw_counts);
        for (int visited_count = 1; visited_count <= 2; visited_count++) {
            for (const auto &animal : zoos[curr_zoo]) saw_counts[animal]++;
            f(f, curr_zoo + 1, cost + c[curr_zoo] * visited_count, saw_counts);
        }
        for (int visited_count = 1; visited_count <= 2; visited_count++) {
            for (const auto &animal : zoos[curr_zoo]) saw_counts[animal]--;
        }
        return;
    };

    std::vector<int> saw_counts(m);
    dfs(dfs, 0, 0LL, saw_counts);

    std::cout << ans << std::endl;
    return 0;
}