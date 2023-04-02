#include <set>
#include <iostream>
#include <vector>

int main() {
    int n, x;
    std::cin >> n >> x;

    std::vector<int> a(n);
    std::set<int> num_set;
    for (auto &num : a) {
        std::cin >> num;
        num_set.insert(num);
    }

    bool satisfies = false;
    for (const auto &num : a) {
        if (num_set.find(num - x) != num_set.end()) {
            satisfies = true;
        }
    }
    
    std::cout << (satisfies ? "Yes" : "No") << std::endl;
    return 0;
}