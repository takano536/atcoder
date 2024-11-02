#include <iostream>
#include <map>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::map<int, int> prev_num;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        if (prev_num.contains(a)) {
            std::cout << prev_num[a] << ' ';
        } else {
            std::cout << -1 << ' ';
        }
        prev_num[a] = i + 1;
    }
    std::cout << std::endl;
    return 0;
}