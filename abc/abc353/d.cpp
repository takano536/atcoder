#include <iostream>
#include <string>
#include <vector>

#include <atcoder/modint>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> pows(11);
    long long curr = 1;
    for (int i = 0; i < 11; i++) {
        pows[i] = curr;
        curr *= 10;
    }

    std::vector<int> a(n);
    std::vector<long long> len(n);
    for (int i = 0; i < n; i++) {
        std::string ai;
        std::cin >> ai;
        a[i] = std::stoi(ai);
        len[i] = pows[ai.size()];
    }

    std::vector<atcoder::modint> a_cumsum(n + 1);
    for (int i = 0; i < n; i++) {
        a_cumsum[i + 1] = a_cumsum[i] + a[i];
    }

    std::vector<atcoder::modint> len_cumsum(n + 1);
    for (int i = 0; i < n; i++) {
        len_cumsum[i + 1] = len_cumsum[i] + len[i];
    }

    atcoder::modint ans = 0;
    atcoder::modint buff = 0;
    for (int i = 0; i < n; i++) {
        ans += a_cumsum[n] - a_cumsum[i + 1];
        buff = a[i];
        buff *= len_cumsum[n] - len_cumsum[i + 1];
        ans += buff;
    }

    std::cout << ans.val() << std::endl;
    return 0;
}