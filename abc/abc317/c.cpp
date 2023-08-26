#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(m), b(m), c(m);
    std::vector<std::vector<int>> cost(n, std::vector<int>(n, -1));
    for (int i = 0; i < m; ++i) {
        std::cin >> a[i] >> b[i] >> c[i];
        a[i]--, b[i]--;
        cost[a[i]][b[i]] = c[i];
        cost[b[i]][a[i]] = c[i];
    }
    std::vector<int> idxs(n);
    for (int i = 0; i < n; ++i) {
        idxs[i] = i;
    }

    long long ans = c[0];
    do {
        long long cost_sum = 0;
        for (int i = 0; i < n - 1; i++) {
            if (cost[idxs[i]][idxs[i + 1]] < 0) {
                break;
            }
            cost_sum += cost[idxs[i]][idxs[i + 1]];
        }
        ans = std::max(ans, cost_sum);
    } while (std::next_permutation(idxs.begin(), idxs.end()));

    std::cout << ans << std::endl;
    return 0;
}