#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(m), b(m);
    for (int i = 0; i < m; i++) {
        std::cin >> a[i] >> b[i];
    }

    std::vector<bool> is_master(n);
    for (int i = 0; i < m; i++) {
        is_master[a[i] - 1] = true;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) {
                continue;
            }
            if (a[i] == b[j]) {
                is_master[a[i] - 1] = false;
            }
        }
    }

    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (is_master[i]) {
            ans = i + 1;
        }
    }

    std::cout << (std::count(is_master.begin(), is_master.end(), true) == 1 ? ans : -1) << std::endl;
}