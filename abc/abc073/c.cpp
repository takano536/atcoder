#include <iostream>
#include <map>
#include <ranges>

int main() {
    int n;
    std::cin >> n;

    std::map<int, bool> exists;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        exists[a] = !exists[a];
    }

    int ans = 0;
    for (const auto v : std::views::values(exists)) ans += v;
    std::cout << ans << std::endl;
    return 0;
}