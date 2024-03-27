#include <iostream>
#include <set>
#include <vector>

const int NA = -1;
int ans = NA;

void calc_fun(int curr_rate, std::set<int> &idxes, const std::vector<std::vector<int>> &a) {
    if (idxes.empty()) {
        ans = std::max(ans, curr_rate);
        return;
    }

    const int i = *idxes.begin();
    idxes.erase(idxes.begin());
    for (const auto &j : idxes) {
        if (j <= i) {
            continue;
        }
        auto next_idxes = idxes;
        next_idxes.erase(j);
        calc_fun(curr_rate == NA ? a[i][j] : curr_rate ^ a[i][j], next_idxes, a);
    }
    return;
}

int main() {
    int n;
    std::cin >> n;
    std::vector a(2 * n - 1, std::vector<int>(2 * n));
    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = i + 1; j < 2 * n; j++) {
            std::cin >> a[i][j];
        }
    }

    std::set<int> idxes;
    for (int i = 0; i < 2 * n; i++) {
        idxes.insert(i);
    }
    calc_fun(NA, idxes, a);

    std::cout << ans << std::endl;
    return 0;
}