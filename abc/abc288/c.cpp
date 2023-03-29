#include <iostream>
#include <vector>

#include <atcoder/dsu>

int main() {
    int n, m;
    std::cin >> n >> m;

    atcoder::dsu union_find(n);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;

        if (union_find.leader(a) == union_find.leader(b)) {
            ans++;
        }
        union_find.merge(a, b);
    }

    std::cout << ans << std::endl;
    return 0;
}