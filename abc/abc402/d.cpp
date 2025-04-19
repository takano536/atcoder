#include <iostream>
#include <vector>

#include <atcoder/modint>

int main() {
    int n, m;
    std::cin >> n >> m;
    atcoder::modint::set_mod(n);

    std::vector<int> cnts(2 * n + 1);
    for (int _ = 0; _ < m; _++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        atcoder::modint i = a;
        atcoder::modint j = b;

        atcoder::modint k = j + i;
        if (k == 0) {
            atcoder::modint x = j + i - 1;
            cnts[x.val() + n]++;
        } else {
            cnts[k.val()]++;
        }
    }

    long long ans = 0;
    std::vector<long long> cumsum(cnts.size() + 1);
    for (std::size_t i = 0; i < cnts.size(); i++) {
        cumsum[i + 1] = cumsum[i] + cnts[i];
    }
    for (std::size_t i = 1; i <= cnts.size(); i++) {
        ans += (cumsum[i] - cumsum[i - 1]) * (cumsum.back() - cumsum[i]);
    }

    std::cout << ans << std::endl;
}