#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> h(n);
    for (auto &hi : h) std::cin >> hi;

    long long ans = 0;
    int i = 0;
    int offset = 0;
    while (i < n) {

        while (offset % 3 != 0) {
            offset++;
            if (offset % 3 == 0) {
                h[i] -= 3;
            } else {
                h[i]--;
            }
            ans++;
            if (h[i] <= 0) break;
        }
        if (h[i] <= 0) {
            i++;
            continue;
        }
        offset = 0;

        ans += h[i] / 5 * 3;
        h[i] %= 5;

        while (h[i] > 0) {
            if ((ans + 1) % 3 == 0) {
                h[i] -= 3;
            } else {
                h[i]--;
            }
            ans++;
            offset++;
        }
        i++;
    }

    std::cout << ans << std::endl;
    return 0;
}