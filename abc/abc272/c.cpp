#include <iostream>
#include <set>

int main() {
    int n;
    std::cin >> n;

    std::set<long long> odds, evens;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        (a % 2 ? odds : evens).insert(a);
    }

    long long ans = -1;
    if (odds.size() >= 2) ans = std::max(*std::prev(odds.end()) + *std::prev(odds.end(), 2), ans);
    if (evens.size() >= 2) ans = std::max(*std::prev(evens.end()) + *std::prev(evens.end(), 2), ans);

    std::cout << ans << std::endl;
    return 0;
}