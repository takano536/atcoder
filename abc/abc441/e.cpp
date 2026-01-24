#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <atcoder/fenwicktree>

long long count_inversions(const std::vector<int> &values) {
    const int n = values.size();

    std::vector<int> compressed = values;
    std::ranges::sort(compressed);
    compressed.erase(std::unique(compressed.begin(), compressed.end()), compressed.end());

    auto to_index = [&](int x) {
        return lower_bound(compressed.begin(), compressed.end(), x) - compressed.begin();
    };

    const int compressed_num = compressed.size();
    atcoder::fenwick_tree<long long> fenwick(compressed_num);

    long long inv_count = 0;
    for (int i = 0; i < n; ++i) {
        const int idx = to_index(values[i]);
        inv_count += fenwick.sum(idx + 1, compressed_num);
        fenwick.add(idx, 1);
    }

    return inv_count;
}

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;

    std::vector<long long> a_cumsum(n + 1), b_cumsum(n + 1);
    std::vector<int> diffs(n + 1);
    for (int i = 0; i < n; i++) {
        a_cumsum[i + 1] = a_cumsum[i] + (s[i] == 'A');
        b_cumsum[i + 1] = b_cumsum[i] + (s[i] == 'B');
        diffs[i + 1] = b_cumsum[i + 1] - a_cumsum[i + 1];
    }

    std::cout << count_inversions(diffs) << std::endl;
    return 0;
}