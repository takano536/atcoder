#include <iostream>
#include <queue>

int main() {
    int q;
    std::cin >> q;

    std::queue<int> que;

    while (q--) {
        int query;
        std::cin >> query;

        if (query == 1) {
            int x;
            std::cin >> x;
            que.push(x);
        } else {
            std::cout << que.front() << std::endl;
            que.pop();
        }
    }
    return 0;
}