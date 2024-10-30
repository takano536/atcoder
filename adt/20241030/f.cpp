#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> q(n), a(n), b(n);
    for (auto &qi : q) std::cin >> qi;
    for (auto &ai : a) std::cin >> ai;
    for (auto &bi : b) std::cin >> bi;

    int a_cnt = 0;
    std::vector<int> curr_q(n);
    bool is_exceeded = false;
    while (true) {
        for (int i = 0; i < n; i++) {
            curr_q[i] += a[i];
            if (curr_q[i] > q[i]) is_exceeded = true;
        }
        if (is_exceeded) break;
        a_cnt++;
    }
    for (int i = 0; i < n; i++) curr_q[i] -= a[i];

    is_exceeded = false;
    int b_cnt = 0;
    while (true) {
        for (int i = 0; i < n; i++) {
            curr_q[i] += b[i];
            if (curr_q[i] > q[i]) is_exceeded = true;
        }
        if (is_exceeded) break;
        b_cnt++;
    }
    for (int i = 0; i < n; i++) curr_q[i] -= b[i];

    int ans = a_cnt + b_cnt;
    for (int i = 0; i < a_cnt; i++) {
        is_exceeded = false;
        for (int i = 0; i < n; i++) curr_q[i] -= a[i];
        while (true) {
            for (int i = 0; i < n; i++) {
                curr_q[i] += b[i];
                if (curr_q[i] > q[i]) is_exceeded = true;
            }
            if (is_exceeded) break;
            b_cnt++;
        }
        for (int i = 0; i < n; i++) curr_q[i] -= b[i];
        ans = std::max(a_cnt - i - 1 + b_cnt, ans);
    }

    std::cout << ans << std::endl;
    return 0;
}