#include <iostream>
#include <map>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::map<int, int> cnts;
    std::vector<int> a(n);
    for (auto &ai : a) {
        std::cin >> ai;
        cnts[ai]++;
    }

    std::map<int, int> cnt_idxes;
    for (int i = 0; const auto &[k, _] : cnts) cnt_idxes[k] = i++;

    std::vector<int> ans(n);
    for (const auto &[k, v] : cnt_idxes) ans[cnts.size() - v - 1] += cnts[k];

    for (const auto &num : ans) std::cout << num << std::endl;

    return 0;
}