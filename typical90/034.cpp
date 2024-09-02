#include <iostream>
#include <map>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    int ans = 1;
    int tail = 0;
    int head = 0;
    std::map<int, int> cnts = {{a[0], 1}};
    while (head < n - 1) {
        if (head < n - 1) head++;
        cnts[a[head]]++;
        while (cnts.size() > static_cast<std::size_t>(k)) {
            cnts[a[tail]]--;
            if (cnts[a[tail]] == 0) cnts.erase(a[tail]);
            tail++;
        }
        ans = std::max<int>(head - tail + 1, ans);
    }

    std::cout << ans << std::endl;
    return 0;
}