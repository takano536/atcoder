#include <iostream>
#include <utility>
#include <vector>

int main()
{
    long long l;
    int n1, n2;
    std::cin >> l >> n1 >> n2;

    std::vector<std::pair<int, long long>> v1(n1), v2(n2);
    for (auto &v : v1) {
        std::cin >> v.first >> v.second;
    }
    for (auto &v : v2) {
        std::cin >> v.first >> v.second;
    }

    long long ans = 0;
    auto v1_iter = v1.begin(), v2_iter = v2.begin();
    long long v1_idx = 0, v2_idx = 0;
    while (v1_iter != v1.end() && v2_iter != v2.end()) {
        if (v1_iter->first == v2_iter->first) {
            ans += std::min(v1_iter->second + v1_idx, v2_iter->second + v2_idx) - std::max(v1_idx, v2_idx);
        }

        if (v1_idx + v1_iter->second <= v2_idx + v2_iter->second) {
            v1_idx += v1_iter->second;
            v1_iter++;
        } else {
            v2_idx += v2_iter->second;
            v2_iter++;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}