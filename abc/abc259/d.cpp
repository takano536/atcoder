#include <iostream>
#include <set>
#include <tuple>
#include <utility>
#include <vector>

#include <atcoder/dsu>

int main() {
    int n;
    std::cin >> n;

    std::pair<int, int> s, t;
    std::cin >> s.first >> s.second >> t.first >> t.second;

    std::vector<int> x(n), y(n), r(n);
    for (int i = 0; i < n; i++) std::cin >> x[i] >> y[i] >> r[i];

    std::set<int> s_idxes, t_idxes;
    for (int i = 0; i < n; i++) {
        long long sx_diff = static_cast<long long>(s.first) - x[i];
        long long sy_diff = static_cast<long long>(s.second) - y[i];
        if (sx_diff * sx_diff + sy_diff * sy_diff == static_cast<long long>(r[i]) * r[i]) {
            s_idxes.insert(i);
        }

        long long tx_diff = static_cast<long long>(t.first) - x[i];
        long long ty_diff = static_cast<long long>(t.second) - y[i];
        if (tx_diff * tx_diff + ty_diff * ty_diff == static_cast<long long>(r[i]) * r[i]) {
            t_idxes.insert(i);
        }
    }

    auto is_connected = [](const std::tuple<int, int, int> c1, const std::tuple<int, int, int> c2) {
        auto get = [](std::tuple<int, int, int> t) -> std::tuple<int, int, int> { return {std::get<0>(t), std::get<1>(t), std::get<2>(t)}; };
        auto [x1, y1, r1] = get(c1);
        auto [x2, y2, r2] = get(c2);

        long long x_diff = static_cast<long long>(x1) - x2;
        long long y_diff = static_cast<long long>(y1) - y2;
        long long r_diff = static_cast<long long>(r1) - r2;
        long long r_sum = static_cast<long long>(r1) + r2;

        long long center_dist = x_diff * x_diff + y_diff * y_diff;
        long long radius_dist = r_diff * r_diff;
        long long radius_sum = r_sum * r_sum;

        return radius_dist <= center_dist && center_dist <= radius_sum;
    };

    atcoder::dsu union_find(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (!is_connected({x[i], y[i], r[i]}, {x[j], y[j], r[j]})) continue;

            union_find.merge(i, j);
        }
    }

    bool is_reachable = false;
    for (const auto &si : s_idxes) {
        for (const auto &ti : t_idxes) {
            if (union_find.same(si, ti)) is_reachable = true;
        }
    }

    std::cout << (is_reachable ? "Yes" : "No") << std::endl;
    return 0;
}