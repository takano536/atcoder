#include <iostream>
#include <map>
#include <vector>

#include <atcoder/dsu>

int main() {
    int n, m;
    std::cin >> n >> m;
    atcoder::dsu dsu(n);
    std::vector<int> indegrees(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        dsu.merge(a, b);
        indegrees[a]++;
        indegrees[b]++;
    }

    long long ans = 0;
    auto groups = dsu.groups();
    for (const auto &group : groups) {
        long long cnt = 0;
        for (const auto &v : group) {
            cnt += indegrees[v];
        }
        cnt /= 2;
        ans += static_cast<long long>(group.size()) * (group.size() - 1) / 2 - cnt;
    }
    std::cout << ans << std::endl;
    return 0;
}