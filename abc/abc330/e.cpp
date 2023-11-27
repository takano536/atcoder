#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (auto &in : a) {
        std::cin >> in;
    }

    std::map<int, int> cnts;
    for (const auto &nun : a) {
        cnts[nun]++;
    }

    std::set<int> mexs;
    for (int i = 0; i <= n; i++) {
        if (cnts[i] == 0) {
            mexs.insert(i);
        }
    }

    for (int cnt = 0; cnt < q; cnt++) {
        int i, x;
        std::cin >> i >> x;
        i--;

        cnts[a[i]]--;
        cnts[x]++;

        if (cnts[a[i]] == 0) {
            mexs.insert(a[i]);
        }
        mexs.erase(x);

        std::cout << *mexs.begin() << std::endl;
        a[i] = x;
    }
    return 0;
}