#include <deque>
#include <iostream>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::deque<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    while (q--) {
        int t, x, y;
        std::cin >> t >> x >> y;
        x--, y--;

        switch (t) {
            case 1:
                std::swap(a[x], a[y]);
                break;

            case 2:
                a.push_front(a.back());
                a.pop_back();
                break;

            case 3:
                std::cout << a[x] << std::endl;
                break;

            default:
                return -1;
        }
    }
    return 0;
}