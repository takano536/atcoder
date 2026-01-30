#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> reviewer_counts(n, n - 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        reviewer_counts[a]--;
        reviewer_counts[b]--;
    }

    for (const auto &count : reviewer_counts) {
        const long long ans = (count >= 3 ? static_cast<long long>(count) * (count - 1) * (count - 2) / 3 / 2 : 0);
        std::cout << ans << ' ';
    }
    std::cout << std::endl;
    return 0;
}