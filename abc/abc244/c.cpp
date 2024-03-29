#include <iostream>
#include <numeric>
#include <set>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(2 * n + 1);
    std::iota(v.begin(), v.end(), 1);
    std::set<int> nums(v.begin(), v.end());
    for (int i = 0; i <= n; i++) {
        int x;
        std::cout << *nums.begin() << std::endl;
        std::cin >> x;
        nums.erase(nums.begin());
        nums.erase(x);
    }
    return 0;
}