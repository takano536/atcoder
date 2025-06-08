#include <iostream>
#include <queue>
#include <stdexcept>
#include <tuple>
#include <vector>

#include <atcoder/dsu>

int main() {
    constexpr long long INF = 8e18;

    int n, q;
    std::cin >> n >> q;

    std::vector<std::tuple<int, int, int>> vertices(n);
    for (int i = 0; auto &[x, y, index] : vertices) {
        std::cin >> x >> y;
        index = i++;
    }

    std::priority_queue<
        std::tuple<long long, int, int>,
        std::vector<std::tuple<long long, int, int>>,
        std::greater<std::tuple<long long, int, int>>
    > que;
    for (const auto &[xi, yi, i] : vertices) {
        for (const auto &[xj, yj, j] : vertices) {
            if (i >= j) continue;
            const long long dist = static_cast<long long>(std::abs(xi - xj)) + std::abs(yi - yj);
            que.emplace(dist, i, j);
        }
    }

    atcoder::dsu union_find(n * 2);
    int index = n;
    while (q--) {
        int op;
        std::cin >> op;

        switch (op) {
            case 1: {
                int a, b;
                std::cin >> a >> b;
                for (const auto &[x, y, i] : vertices) {
                    const long long dist = static_cast<long long>(std::abs(x - a)) + std::abs(y - b);
                    que.emplace(dist, i, index);
                }
                vertices.emplace_back(a, b, index++);
                break;
            }

            case 2: {
                if (que.empty()) {
                    std::cout << -1 << std::endl;
                    break;
                }

                auto k = INF;
                while (!que.empty()) {
                    const auto [dist, i, j] = que.top();
                    if (k != INF && dist > k) break;

                    que.pop();
                    if (union_find.same(i, j)) continue;
                    if (k == INF) k = dist;
                    union_find.merge(i, j);
                }

                std::cout << (k == INF ? -1 : k) << std::endl;
                break;
            }

            case 3: {
                int u, v;
                std::cin >> u >> v;
                u--, v--;
                std::cout << (union_find.same(u, v) ? "Yes" : "No") << std::endl;
                break;
            }

            default: throw std::runtime_error("invalid option");
        }
    }
    return 0;
}