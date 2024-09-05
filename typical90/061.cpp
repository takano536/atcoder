#include <deque>
#include <iostream>

int main() {
    int q;
    std::cin >> q;

    std::deque<int> deq;
    while (q--) {
        int t, x;
        std::cin >> t >> x;

        switch (t) {
            case 1:
                deq.push_front(x);
                break;
            case 2:
                deq.push_back(x);
                break;
            case 3:
                std::cout << deq[x - 1] << std::endl;
                break;
            default:
                return -1;
        }
    }
    return 0;
}