#include <iostream>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    int ans = 0;
    std::vector<bool> is_black(n + 2);
    while (q--) {
        int a;
        std::cin >> a;

        const auto prev = is_black[a - 1];
        const auto curr = is_black[a];
        const auto next = is_black[a + 1];
        if (!prev && !curr && !next) ans++;
        if (!prev && curr && !next) ans--;
        if (prev && !curr && next) ans--;
        if (prev && curr && next) ans++;

        is_black[a] = !is_black[a];
        std::cout << ans << '\n';
    }
    std::cout << std::flush;
    return 0;
}