#include <iostream>
#include <map>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::map<int, std::vector<int>> idxes;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        idxes[a[i]].push_back(i);
    }

    long long ans = 0;
    for (const auto &[k, v] : idxes) {
        if (v.size() < 2) continue;
        for (std::size_t i = 0; i < v.size() - 1; i++) {
            int i_num = i + 1;
            int j_num = v[i + 1] - v[i] - 1;
            int k_num = v.size() - i_num;
            ans += static_cast<long long>(i_num) * j_num * k_num;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}