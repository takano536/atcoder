#include <algorithm>
#include <iostream>
#include <set>

int main() {
    int q;
    std::cin >> q;

    while (q--) {
        int n;
        std::cin >> n;

        int curr, tail;
        std::set<int> s;
        std::cin >> curr;
        for (int i = 0; i < n - 2; i++) {
            int si;
            std::cin >> si;
            s.insert(si);
        }
        std::cin >> tail;

        int ans = 2;
        while (!s.empty() && curr * 2 < tail) {
            auto iter = s.upper_bound(curr * 2);
            if (iter == s.begin()) break;
            if (*--iter > curr * 2) break;
            curr = *iter;
            s.erase(iter);
            ans++;
        }

        std::cout << (curr * 2 >= tail ? ans : -1) << '\n';
    }
    std::cout << std::flush;
    return 0;
}