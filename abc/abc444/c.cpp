#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
    constexpr int NA = 1 << 30;

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    std::ranges::sort(a);

    auto restore_len = [NA](const std::vector<int> &a, const int orig_len = 1 << 30) {
        const int n = a.size();
        if (n % 2) return NA;

        int len = NA;
        bool is_possible = true;
        for (int i = 0; i < (n + 2 - 1) / 2; i++) {
            if (i == n - 1 - i) is_possible = false;
            const int curr_len = a[i] + a[n - 1 - i];
            if (orig_len != NA && curr_len != orig_len) is_possible = false;
            if (len != NA && len != curr_len) is_possible = false;
            len = curr_len;
        }

        return is_possible ? len : NA;
    };

    std::set<int> ans;
    if (std::ranges::all_of(a, [&a](int ai) { return ai == a[0]; })) ans.insert(a[0]);
    ans.insert(restore_len(a));

    const int longest = a.back();
    while (!a.empty() && a.back() == longest) a.pop_back();
    if (!a.empty()) ans.insert(restore_len(a, longest));

    ans.erase(NA);
    for (const auto &len : ans) std::cout << len << ' ';
    std::cout << std::endl;
    return 0;
}