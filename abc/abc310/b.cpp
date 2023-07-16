#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> p(n);
    std::vector<std::set<int>> f(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
        int c;
        std::cin >> c;
        std::set<int> func;
        for (int j = 0; j < c; j++) {
            int input;
            std::cin >> input;
            func.insert(input);
        }
        f[i] = func;
    }

    bool satisfied = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }

            if (p[i] < p[j]) {
                continue;
            }

            if (f[i].size() > f[j].size()) {
                continue;
            }

            std::set<int> res;
            std::set_intersection(f[i].begin(), f[i].end(), f[j].begin(), f[j].end(), std::inserter(res, res.end()));
            if (res != f[i]) {
                continue;
            }

            if (p[i] == p[j] && f[i].size() == f[j].size()) {
                continue;
            }

            satisfied = true;
        }
    }

    std::cout << (satisfied ? "Yes" : "No") << std::endl;
    return 0;
}