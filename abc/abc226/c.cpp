#include <iostream>
#include <vector>

long long dfs(int curr, std::vector<bool> &is_learned, const std::vector<int> &t, const std::vector<std::vector<int>> &a) {
    long long cost = t[curr];
    is_learned[curr] = true;
    for (const auto &next : a[curr]) {
        if (is_learned[next]) {
            continue;
        }
        cost += dfs(next, is_learned, t, a);
    }
    return cost;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> t(n), k(n);
    std::vector a(n, std::vector<int>());
    std::vector<int> start_curr_idxes;
    for (int i = 0; i < n; i++) {
        std::cin >> t[i] >> k[i];
        a[i].resize(k[i]);
        for (auto &input : a[i]) {
            std::cin >> input;
            input--;
        }
    }

    std::vector<bool> is_learned(n);
    std::cout << dfs(n - 1, is_learned, t, a) << std::endl;
    return 0;
}