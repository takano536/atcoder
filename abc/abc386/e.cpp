#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    bool is_complementary = (n - k < k);
    if (is_complementary) k = n - k;

    long long total_xor = 0;
    std::vector<long long> a(n);
    for (auto &ai : a) std::cin >> ai, total_xor ^= ai;

    long long ans = (is_complementary ? total_xor : 0);

    auto dfs = [&](auto &&f, long long curr, std::vector<int> &used_idxes) {
        if (used_idxes.size() == static_cast<std::size_t>(k)) {
            ans = std::max(ans, curr);
            return;
        }

        long long ret = curr;
        for (int i = used_idxes.empty() ? 0 : used_idxes.back() + 1; i < n; i++) {
            used_idxes.push_back(i);
            ret ^= a[i];

            f(f, ret, used_idxes);

            ret ^= a[i];
            used_idxes.pop_back();
        }

        return;
    };

    std::vector<int> used_idxes;
    dfs(dfs, ans, used_idxes);

    std::cout << ans << std::endl;
    return 0;
}