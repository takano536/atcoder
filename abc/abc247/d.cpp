#include <iostream>
#include <list>
#include <utility>
#include <vector>

int main() {
    int q;
    std::cin >> q;
    std::list<std::pair<int, int>> pipe;
    for (int query = 0; query < q; query++) {
        int opt;
        std::cin >> opt;
        if (opt == 1) {
            int x, c;
            std::cin >> x >> c;
            pipe.push_back({x, c});
        } else {
            int c;
            std::cin >> c;
            long long cnt = 0;
            long long ans = 0;
            while (cnt < c) {
                auto top = pipe.front();
                pipe.pop_front();
                if (cnt + top.second > c) {
                    top.second -= c - cnt;
                    ans += static_cast<long long>(top.first) * (c - cnt);
                    cnt = c;
                    pipe.push_front(top);
                } else {
                    ans += static_cast<long long>(top.first) * top.second;
                    cnt += top.second;
                }
            }
            std::cout << ans << std::endl;
        }
    }
    return 0;
}