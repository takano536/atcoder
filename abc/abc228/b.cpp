#include <iostream>
#include <vector>

int main() {
    int n, x;
    std::cin >> n >> x;
    x--;

    std::vector<int> a(n);
    for (auto &ai : a) {
        std::cin >> ai;
        ai--;
    }

    std::vector<bool> has_visited(n);
    int curr = x;
    int ans = 0;
    while (!has_visited[curr]) {
        has_visited[curr] = true;
        curr = a[curr];
        ans++;
    }

    std::cout << ans << std::endl;
    return 0;
}