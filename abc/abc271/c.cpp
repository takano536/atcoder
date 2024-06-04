#include <iostream>
#include <set>

int main() {
    int n;
    std::cin >> n;

    std::multiset<int> a;
    int unused_cnt = 0;
    for (int i = 0; i < n; i++) {
        int ai;
        std::cin >> ai;
        if (a.contains(ai)) {
            unused_cnt++;
            continue;
        }
        a.insert(ai);
    }

    int ans = 1;
    int head = -1;
    int tail = a.size();
    while (true) {
        if (a.contains(ans)) {
            ans++;
            head++;
            continue;
        }

        if (unused_cnt >= 2) {
            unused_cnt -= 2;
        } else if (unused_cnt == 1) {
            tail--;
            unused_cnt--;
            if (tail <= head) break;
            a.erase(std::prev(a.end()));
        } else {
            tail -= 2;
            if (tail <= head) break;
            a.erase(std::prev(a.end()));
            a.erase(std::prev(a.end()));
        }

        ans++;
    }
    ans--;

    std::cout << ans << std::endl;
    return 0;
}