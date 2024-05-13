#include <iostream>
#include <set>

int main() {
    int n;
    std::cin >> n;

    std::set<int> d;
    for (int i = 0; i < n; i++) {
        int di;
        std::cin >> di;
        d.insert(di);
    }

    std::cout << d.size() << std::endl;
    return 0;
}