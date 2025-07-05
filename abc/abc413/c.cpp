#include <iostream>
#include <queue>
#include <stdexcept>
#include <utility>

void process_query(std::queue<std::pair<int, int>> &a) {
    int op;
    std::cin >> op;

    switch (op) {
        case 1: {
            int c, x;
            std::cin >> c >> x;
            a.emplace(c, x);
            break;
        }
        case 2: {
            int k;
            std::cin >> k;

            long long ans = 0;
            while (k > 0) {
                auto &[num, ai] = a.front();
                const auto pop_num = std::min(k, num);
                ans += static_cast<long long>(ai) * pop_num;
                k -= pop_num, num -= pop_num;
                if (num == 0) a.pop();
            }

            std::cout << ans << '\n';
            break;
        }
        default: throw std::runtime_error("Invalid option");
    }
}

int main() {
    int q;
    std::cin >> q;

    std::queue<std::pair<int, int>> a;

    while (q--) process_query(a);

    std::cout << std::flush;
    return 0;
}