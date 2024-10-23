#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

int main() {
    constexpr long long INF = 1LL << 60;

    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::size_t k;
        std::cin >> n >> k;

        std::vector<std::pair<int, int>> seqs(n);
        for (auto &[a, _] : seqs) std::cin >> a;
        for (auto &[_, b] : seqs) std::cin >> b;

        std::ranges::sort(seqs);

        std::multiset<int> que;
        long long b_sum = 0;
        long long ans = INF;
        for (const auto &[a, b] : seqs) {
            que.insert(b);
            b_sum += b;
            if (que.size() > k) {
                b_sum -= *std::prev(que.end());
                que.erase(std::prev(que.end()));
            }
            if (que.size() == k) ans = std::min(ans, b_sum * a);
        }

        std::cout << ans << std::endl;
    }
    return 0;
}