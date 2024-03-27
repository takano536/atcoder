#include <iostream>
#include <map>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (auto &ai : a) {
        std::cin >> ai;
    }

    std::map<int, std::vector<int>> idxes;
    for (int i = 0; i < n; i++) {
        idxes[a[i]].push_back(i + 1);
    }

    for (int query = 0; query < q; query++) {
        int x;
        std::size_t k;
        std::cin >> x >> k;
        k--;
        std::cout << (!idxes.contains(x) || k >= idxes[x].size() ? -1 : idxes[x][k]) << std::endl;
    }
    return 0;
}