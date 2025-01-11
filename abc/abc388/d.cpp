#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    long long total = 0;
    for (auto &ai : a) {
        std::cin >> ai;
        total += ai;
    }

    std::multiset<int> que;

    long long stone_num = 0;
    for (int i = 0; i < n; i++) {
        while (!que.empty() && *que.begin() < i) que.erase(que.begin());
        a[i] += que.size();
        const auto give_num = std::min<long long>(a[i], n - i - 1);
        a[i] -= give_num;
        que.insert(give_num + i);
        if (i == n - 1) a[i] = total - stone_num;
        std::cout << a[i] << ' ';
        stone_num += a[i];
    }
    std::cout << std::endl;
    return 0;
}