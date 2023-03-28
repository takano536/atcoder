#include <iostream>
#include <set>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> a(m);
    for (auto &vec : a) {
        int c;
        std::cin >> c;

        vec.resize(c);
        for (auto &num : vec) {
            std::cin >> num;
        }
    }

    int ans = 0;
    for (int bit = 0; bit < (1 << m); bit++) {
        std::set<int> st;
        for (int i = 0; i < m; ++i) {
            if (!(bit & (1 << i))) {
                continue;
            }
            for (auto num : a[i]) {
                st.insert(num);
            }
        }

        ans += static_cast<int>(static_cast<int>(st.size()) == n);
    }

    std::cout << ans << std::endl;
    return 0;
}