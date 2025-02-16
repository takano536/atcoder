#include <iostream>
#include <stdexcept>

#include <atcoder/fenwicktree>

int main() {
    constexpr int MAX_SNAKE_NUM = 3e5;

    int q;
    std::cin >> q;

    int head = 0;
    int tail = 0;
    atcoder::fenwick_tree<long long> queue(MAX_SNAKE_NUM);

    while (q--) {
        int query;
        std::cin >> query;

        switch (query) {
            case 1: {
                int l;
                std::cin >> l;
                queue.add(tail, l);
                tail++;
                break;
            }
            case 2: {
                queue.add(head, -queue.sum(head, head + 1));
                head++;
                break;
            }
            case 3: {
                int k;
                std::cin >> k;
                k -= 1;
                std::cout << queue.sum(head, head + k) << std::endl;
                break;
            }
            default: throw std::runtime_error("Invalid query");
        }
    }
    return 0;
}