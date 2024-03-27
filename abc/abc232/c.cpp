#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector g1(n, std::vector<bool>(n));
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        g1[a][b] = true;
        g1[b][a] = true;
    }
    std::vector g2(n, std::vector<bool>(n));
    for (int i = 0; i < m; i++) {
        int c, d;
        std::cin >> c >> d;
        c--, d--;
        g2[c][d] = true;
        g2[d][c] = true;
    }

    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    bool is_satisfied = false;
    do {
        bool is_same = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                is_same &= g1[p[i]][p[j]] == g2[i][j];
            }
        }

        is_satisfied |= is_same;
    } while (std::next_permutation(p.begin(), p.end()));

    std::cout << (is_satisfied ? "Yes" : "No") << std::endl;
    return 0;
}