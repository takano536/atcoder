#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> p(n);
    for (auto &pi : p) {
        std::cin >> pi;
        pi--;
    }

    const int NA = -1;
    std::vector<int> ans(n, -1);
    std::set<int> tops;
    std::vector<int> unders(n);
    std::vector<int> cnts(n);
    for (int i = 0; const auto &pi : p) {

        auto iter = tops.lower_bound(pi);
        if (iter == tops.end()) {
            tops.insert(pi);
            cnts[pi] = 1;
            unders[pi] = NA;
        } else {
            cnts[pi] = cnts[*iter] + 1;
            cnts[*iter] = 0;
            unders[pi] = *iter;
            tops.erase(iter);
            tops.insert(pi);
        }

        if (cnts[pi] == k) {
            cnts[pi] = 0;
            int curr = pi;
            while (curr != NA) {
                ans[curr] = i + 1;
                curr = unders[curr];
            }
            tops.erase(pi);
        }
        i++;
    }

    for (const auto &i : ans) {
        std::cout << i << std::endl;
    }
    return 0;
}