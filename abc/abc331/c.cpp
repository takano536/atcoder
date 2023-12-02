#include <iostream>
#include <map>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::map<long long, int> cnts;
    for (auto &in : a) {
        std::cin >> in;
        cnts[in]++;
    }

    std::vector<long long> cumsum(cnts.size() + 1);
    std::map<int, int> idxs;
    int idx = 0;
    for (const auto &[k, v] : cnts) {
        cumsum[idx + 1] = cumsum[idx] + k * v;
        idxs[k] = idx;
        idx++;
    }

    long long sum = cumsum.back();
    for (int i = 0; i < n; i++) {
        std::cout << sum - cumsum[idxs[a[i]] + 1] << ' ';
    }
    std::cout << std::endl;
    return 0;
}