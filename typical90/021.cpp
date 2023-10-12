#include <iostream>
#include <vector>

#include <atcoder/scc>

int main() {
    int n, m;
    std::cin >> n >> m;

    atcoder::scc_graph graph(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        graph.add_edge(a, b);
    }

    auto scc = graph.scc();
    long ans = 0;
    for (auto &v : scc) {
        ans += v.size() * (v.size() - 1) / 2;
    }

    std::cout << ans << std::endl;
    return 0;
}