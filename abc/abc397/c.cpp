#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    std::vector<int> cumsum(n + 1);
    std::set<int> nums;
    for (int i = 0; i < n; i++) {
        nums.insert(a[i]);
        cumsum[i + 1] += nums.size();
    }

    std::vector<int> rev_a = a;
    std::ranges::reverse(rev_a);
    nums.clear();
    std::vector<int> rev_cumsum(n + 1);
    for (int i = 0; i < n; i++) {
        nums.insert(rev_a[i]);
        rev_cumsum[i + 1] += nums.size();
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        int cnt = 0;
        cnt += cumsum[i];
        cnt += rev_cumsum[n - i];
        ans = std::max(ans, cnt);
    }

    std::cout << ans << std::endl;
    return 0;
}