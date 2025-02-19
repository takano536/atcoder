#include <iostream>
#include <vector>

int main() {
    int r;
    std::cin >> r;

    long long ans = (r - 1) * 4 + 1;

    long long cnt = 0;
    for (int i = 1; i <= r - 1; i++) {
        int ok = 0, ng = r + 1;
        while (ng - ok > 1) {
            auto mid = (ok + ng) / 2;
            long long lhs = 0;
            lhs += static_cast<long long>(i) * i * 2;
            lhs += i * 2;
            lhs += static_cast<long long>(mid) * mid * 2;
            lhs += mid * 2;
            lhs += 1;
            lhs -= static_cast<long long>(r) * r * 2;
            (lhs <= 0 ? ok : ng) = mid;
        }
        cnt += ok;
    }

    ans += cnt * 4;
    std::cout << ans << std::endl;
    return 0;
}