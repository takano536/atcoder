#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int a, b;
    std::cin >> a >> b;

    int ans = 0;
    for (int x = -1000; x <= 1000; x++) {
        std::vector<int> v = {a, b, x};
        std::ranges::sort(v);
        do {
            if (v[1] - v[0] == v[2] - v[1]) {
                ans++;
                break;
            }
        } while (std::next_permutation(v.begin(), v.end()));
    }

    std::cout << ans << std::endl;
    return 0;
}